#include "graphics/Shader.h"

#include <glad/glad.h>
//#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader() : m_id(0) {}

Shader::~Shader()
{
    if (m_id)
        glDeleteProgram(m_id);
}

std::string Shader::loadFile(const std::string& path)
{
    std::ifstream file(path);
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

unsigned int Shader::compile(unsigned int type, const std::string& source)
{
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str();

    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char info[512];
        glGetShaderInfoLog(shader, 512, nullptr, info);
        std::cerr << "Shader compile error:\n" << info << std::endl;
    }

    return shader;
}

bool Shader::load(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vs = loadFile(vertexPath);
    std::string fs = loadFile(fragmentPath);

    unsigned int vertex = compile(GL_VERTEX_SHADER, vs);
    unsigned int fragment = compile(GL_FRAGMENT_SHADER, fs);

    m_id = glCreateProgram();

    glAttachShader(m_id, vertex);
    glAttachShader(m_id, fragment);

    glLinkProgram(m_id);

    int success;
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);

    if (!success)
    {
        char info[512];
        glGetProgramInfoLog(m_id, 512, nullptr, info);
        std::cerr << "Program link error:\n" << info << std::endl;
        return false;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return true;
}

void Shader::use() const
{
    glUseProgram(m_id);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(
        glGetUniformLocation(m_id, name.c_str()),
        1,
        GL_FALSE,
        &mat[0][0]
    );
}

void Shader::setVec3(
    const std::string& name,
    const glm::vec3& value
) const
{
    glUniform3fv(
        glGetUniformLocation(m_id, name.c_str()),
        1,
        glm::value_ptr(value)
    );
}

void Shader::setFloat(
    const std::string& name,
    float value
) const
{
    glUniform1f(
        glGetUniformLocation(m_id, name.c_str()),
        value
    );
}

void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}