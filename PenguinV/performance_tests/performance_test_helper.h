#pragma once

#include <chrono>
#include <list>
#include "../Library/image_buffer.h"

namespace Performance_Test
{
	// A class to measure time of individual test
	class TimerContainer
	{
	public:
		TimerContainer();
		~TimerContainer();

		void start(); // start time measurement
		void stop();  // stop time measurement

		std::pair < double, double > mean(); // returns mean and sigma values
	private:
		std::chrono::time_point < std::chrono::high_resolution_clock > _startTime;
		std::list < double > _time;
	};

	// Functions to generate images
	Bitmap_Image::Image uniformImage(uint32_t width, uint32_t height);
	std::vector< Bitmap_Image::Image > uniformImages(uint32_t count, uint32_t width, uint32_t height);

	uint32_t runCount(); // fixed value for all test loops

	void setFunctionPoolThreadCount(); // by default the value is 4 you can change it to make better results
};