#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use() const;
    
    // Set uniform matrix
    void setMat4(const std::string& name, const glm::mat4& mat) const;
    
private:
    std::string loadShaderSource(const char* filePath);
    void compileShaderProgram(const char* vertexSource, const char* fragmentSource);
    void checkCompileErrors(unsigned int shader, const std::string& type);
    void checkLinkErrors(unsigned int program);
};

#endif
