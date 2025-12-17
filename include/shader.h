#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use() const;
    
private:
    std::string loadShaderSource(const char* filePath);
    void compileShaderProgram(const char* vertexSource, const char* fragmentSource);
    void checkCompileErrors(unsigned int shader, const std::string& type);
    void checkLinkErrors(unsigned int program);
};

#endif
