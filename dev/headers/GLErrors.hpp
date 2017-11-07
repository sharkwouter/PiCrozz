#ifndef _GLERRORS_PICROZZ_AUBIN_KLEVH_
#define _GLERRORS_PICROZZ_AUBIN_KLEVH_

#include <fstream>
#include <exception>
#include <iostream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include <GL/gl.h>

#ifdef LOG_OUTPUT
#  define SHOW_WHERE(exception,err) LOG_OUTPUT << #exception " caught in file :\n\t" __FILE__ "\nCaught before line : " << __LINE__ + offset << "\n\t" << err.what() << std::endl;
#endif

/**
 * @brief namespace containing all the general error managment
 */
namespace GLErrors{
    /**
     * @brief set the message of GL_ERROR if there is an openGL error
     * @return true if there is an openGL error
     */
    bool glGetError();
    
    /**
     * @brief OpenGL error
     */
    class GL_ERROR : public std::exception{
	// static attributes
	static std::string error_;
	///< error message of all unread openGL errors

	// private methods
	/**
	 * @brief add msg to the error message
	 * @param msg : error message to be added
	 */
	static void setErrorMsg(const std::string& msg);
	
    public:
	/**
	 * @brief getter for the error message
	 * @return The error message as a string
	 */
	std::string what();
	
	// friend function
	friend bool glGetError();
    };

    /**
     * @brief Error of glew initialization
     */
    class GLEW_INIT_FAILED : public std::exception{
    public:
	/**
	 * @brief getter for the error message
	 * @return The error message as a string
	 */
	std::string what();
    };
}

#endif
