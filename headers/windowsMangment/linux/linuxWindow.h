#pragma once
#include "coreWindow.h"
#include <string>
#include <functional>
#include <vector>

struct GLFWwindow;
namespace LaughTaleEngine {

	class linuxWindow: public coreWindow
	{
		private:

		public:
			linuxWindow(const std::string& title, unsigned int width, unsigned int height, bool useImGui):
				coreWindow(title, width, height, useImGui){}


			static GLFWwindow* Init(linuxWindow *data);
			static void Shutdown(GLFWwindow* Window);
			static void onUpdate(linuxWindow *window, void *sendor);
			static bool isOpen(GLFWwindow* Window);
			static void setVSync(bool enabled);
			GLFWwindow* Window;
		
			
	};
}