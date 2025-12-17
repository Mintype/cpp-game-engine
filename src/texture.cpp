#include "texture.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>  // For loading image files

// Constructor - Load texture from file and upload to GPU
Texture::Texture(const char* imagePath) : textureUnit(0) {
    // Step 1: Load the image from disk
    int width, height, channels;
    unsigned char* data = loadImage(imagePath, width, height, channels);

    // Check if image loaded successfully
    if (!data) {
        std::cerr << "ERROR: Failed to load texture at path: " << imagePath << std::endl;

        // Load NULL texture to avoid crashes
        data = loadImage("./textures/null_block.png", width, height, channels);

        // If NULL texture also fails, exit
        if (!data) {
            std::cerr << "ERROR: Failed to load fallback NULL texture." << std::endl;
            return;
        }
    }

    // Step 2: Create an OpenGL texture object
    glGenTextures(1, &ID);

    // Step 3: Bind the texture as the active texture
    glBindTexture(GL_TEXTURE_2D, ID);

    // Step 4: Configure texture properties BEFORE uploading data
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Step 5: Determine the format of the image data
    // - channels == 3: RGB (red, green, blue) - 3 bytes per pixel
    // - channels == 4: RGBA (red, green, blue, alpha) - 4 bytes per pixel
    GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;

    // Step 6: Upload the image data to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    // Step 7: Generate mipmaps
    glGenerateMipmap(GL_TEXTURE_2D);

    // Step 8: Free the loaded image data from CPU memory
    stbi_image_free(data);

    // Step 9: Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

// Destructor - Clean up GPU resources
Texture::~Texture() {
    glDeleteTextures(1, &ID);
}

// bind() - Activate this texture for rendering
void Texture::bind() const {
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

// unbind() - Deactivate the current texture
void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

// setTextureUnit() - Specify which texture unit this texture uses
void Texture::setTextureUnit(unsigned int unit) {
    textureUnit = unit;
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

// loadImage() - Private helper to load image from disk
unsigned char* Texture::loadImage(const char* imagePath, int& width, int& height, int& channels) {


    // The '0' parameter means "keep the original number of channels".
    // If we wanted to force RGB (3 channels), we'd pass 3 instead.
    unsigned char* data = stbi_load(imagePath, &width, &height, &channels, 0);

    // Check if loading succeeded
    if (!data) {
        std::cerr << "ERROR: stbi_load failed to load image: " << imagePath << std::endl;
        std::cerr << "Error: " << stbi_failure_reason() << std::endl;
    }

    return data;
}

// configureTexture() - Private helper to set texture properties
void Texture::configureTexture() {
    // Set wrapping mode: What happens at texture edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // Horizontal wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);  // Vertical wrapping

    // Set minification filter: How texture looks when scaled DOWN
    // - GL_LINEAR: Linear filtering without mipmaps
    // - GL_NEAREST: Pixelated/blocky look (fast but low quality)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    // Set magnification filter: How texture looks when scaled UP
    // - GL_LINEAR: Use linear interpolation between pixels (smooth, blurry)
    // - GL_NEAREST: Use nearest pixel (pixelated/blocky look)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
