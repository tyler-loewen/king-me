#include <iostream>
#include "DefaultHUD.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

DefaultHUD::DefaultHUD()
{
   al_init_font_addon();
   al_init_ttf_addon();
   
   this->font = al_load_ttf_font("img/ostrich-regular.ttf", 16, NULL);
}

DefaultHUD::~DefaultHUD()
{
   al_destroy_font(this->font);
}
   
void DefaultHUD::draw(unsigned int display_width, unsigned int display_height, std::string status, std::string current_player, unsigned int pieces_captured)
{
   std::string text("Status: ");

   text += status;
   text += ", Current Player: ";
   text += current_player;
   text += ", Pieces Captured: ";
   text += std::to_string((unsigned long long) pieces_captured);
   
   al_draw_text(this->font, al_map_rgb(255, 255, 255), 10, 5, ALLEGRO_ALIGN_LEFT, text.c_str());
}

