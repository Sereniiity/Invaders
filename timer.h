#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace invader
{
	class timer
	{
		public:
			timer();
			~timer();

			void	start();
			void	stop();
			void	pause();
			void	unpause();
			int	get_ticks();
			bool	is_started();
			bool	is_paused();

		private:
			int	startTicks;
			int	pausedTicks;
			bool	paused;
			bool	started;
	};
};

#endif
