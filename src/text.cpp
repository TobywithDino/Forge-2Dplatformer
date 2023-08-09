#include "headers/text.h"

TTF_Font* Text::font;

int Text::init(){
    const char* path = "res/font/slkscr.ttf";
	font = TTF_OpenFont(path, 32);
	if(font == nullptr){
		printf("Error : can't get font : %s\n", path);
		return -1;
	}
    return 0;
}

Text::Text(){
}

Text::Text(string word, vector2 pos){
    this->word = word;
    this->pos = pos;
}
    
Text::Text(string word, vector2 pos, double sizeMultiplier, SDL_Color color){
    this->word = word;
    this->pos = pos;
    this->sizeMultiplier = sizeMultiplier;
    this->color = color;
}


void Text::update(string word){
    this->word = word;
}

void Text::render(){
    SDL_Surface* text_surf = TTF_RenderText_Solid(font, word.c_str(), color);
    SDL_Texture* text = SDL_CreateTextureFromSurface(gb::getRenderer(), text_surf);
    SDL_Rect dst;
    dst.x = pos.x - ((text_surf->w*sizeMultiplier*gb::getScale()) / 2.0f);
    dst.y = pos.y - ((text_surf->h*sizeMultiplier*gb::getScale()) / 2.0f);
    dst.w = text_surf->w*sizeMultiplier*gb::getScale();
    dst.h = text_surf->h*sizeMultiplier*gb::getScale();
    SDL_RenderCopy(gb::getRenderer(), text, NULL, &dst);

    SDL_DestroyTexture(text);
    SDL_FreeSurface(text_surf);
}