#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <glad/glad.h>

class Texture {
public:
    // The OpenGL texture ID - this is a handle to the texture stored on the GPU
    unsigned int ID;

    // Constructor - Initialize and load a texture from an image file
    Texture(const char* imagePath);

    // Destructor - Clean up GPU resources
    ~Texture();

    // bind() - Activate this texture for rendering
    void bind() const;

    // unbind() - Deactivate the current texture
    void unbind() const;

    // setTextureUnit() - Specify which texture unit this texture uses
    void setTextureUnit(unsigned int unit);

private:
    // Private member variable to store which texture unit this texture is assigned to
    unsigned int textureUnit;

    // loadImage() - Load an image file from disk using stb_image library
    unsigned char* loadImage(const char* imagePath, int& width, int& height, int& channels);

    // configureTexture() - Set up texture properties like filtering and wrapping
    void configureTexture();
};

#endif
