#include <SDL/SDL.h>
#include "csprite.h"

void CFrame::load(char *path) {
	img=SDL_LoadBMP(path);
	// Asignamos el color transparente al color rojo.
	SDL_SetColorKey(img,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(img->format,0,0,0));
	img=SDL_DisplayFormat(img);
}

void CFrame::unload(){
	SDL_FreeSurface(img);
}

CSprite::CSprite(int nf) {
	sprite=new CFrame[nf];
	nframes=nf;
	cont=0;
}

CSprite::CSprite() {
	int nf=1;
	sprite=new CFrame[nf];
	nframes=nf;
	cont=0;
}

void CSprite::finalize() {
	int i;
	for (i=0 ; i<=nframes-1 ; i++)
	sprite[i].unload();
}

void CSprite::addframe(CFrame frame) {
	if (cont<nframes) {
	sprite[cont]=frame;
	cont++;
	}
}

void CSprite::selframe(int nf) {
	if (nf<=nframes) {
	estado=nf;
	}
}

void CSprite::draw(SDL_Surface *superficie) {
	SDL_Rect dest;
	dest.x=posx;
	dest.y=posy;
	SDL_BlitSurface(sprite[estado].img,NULL,superficie,&dest);
}

int CSprite::colision(CSprite sp) {

	int w1,h1,w2,h2,x1,y1,x2,y2;

	w1=getw();
	h1=geth();
	w2=sp.getw();
	h2=sp.geth();
	x1=getx();
	y1=gety();
	x2=sp.getx();
	y2=sp.gety();
	if (((x1+w1)>x2)&&((y1+h1)>y2)&&((x2+w2)>x1)&&((y2+h2)>y1)) {
	return TRUE;
	} 
	else{
		return FALSE;
	}
}
