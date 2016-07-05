#include "../include/StaticSprite.hpp"
#include "../include/Game.hpp"

StaticSprite::StaticSprite() : Sprite()
{

}

StaticSprite::StaticSprite(const char* file, int frameCount, float frameTime) :
Sprite(file, frameCount, frameTime)
{

}

StaticSprite::StaticSprite(const char* file, int frameCount, float frameTime, int loopBackFrame) :
Sprite(file, frameCount, frameTime, loopBackFrame)
{

}

StaticSprite::~StaticSprite()
{

}

void StaticSprite::render(int x, int y, float angle, bool flip)
{
	SDL_Rect dstRect;

	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = clipRect_.w * scaleX_;
	dstRect.h = clipRect_.h * scaleY_;

	SDL_RenderCopyEx ( Game::getInstance().getRenderer(), texture_.get(), &clipRect_, &dstRect, (double)angle, NULL, flip ?  SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE );
}