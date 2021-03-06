#ifndef RULESETINTERFACE_H
#define RULESETINTERFACE_H

#include "PlayerEnum.h"

class RuleSetInterface
{
  public:
   virtual ~RuleSetInterface() {}

   /**
    * Determines if the specified player should be forced to make a jump.
    *
    * @param player - The player who has a jump to make.
    * @param is_king - True if the piece with the possible jump is a king; false otherwise.
    *
    * @return True if the player must make the jump; false otherwise.
    */
   virtual bool mustMakeJumps(PLAYER player, bool is_king) = 0;

   /**
    * Determines if a piece can move or jump backwards.
    *
    * @param player - The player who is wanting to make a move.
    * @param is_king - True if the player is wanting to move a king piece; false otherwise.
    * @param is_jump - True if the player is wanting to jump over a piece; false if the player
    *                  is simply trying to move to an empty tile.
    *
    * @param True if the player can move backwards; false otherwise.
    */ 
   virtual bool canMoveBackwards(PLAYER player, bool is_king, bool is_jump) = 0;
};

#endif
