#include "ballmovement.h"
#include "Collision.h"

ballmovement::ballmovement(float p_x, float p_y, SDL_Texture* p_tex)
: Ballz(p_x, p_y, p_tex) {
    // xspeedB and yspeedB are already initialized in the Ballz constructor
}

void ballmovement::updateLtoR(Entity crates[], int numCrates) {
    xposB += xspeedB; // Move the ball to the right

    if (xposB > 720) { // Check if the ball has gone off the screen (example value, adjust as needed)
        xposB = 30; // Reset xposB to the left edge
    }
    checkCollisionLtoR(crates, numCrates);
}

SDL_Rect ballmovement::GetNotptrDSTBMB()
{
    return Ballz::GetNotptrDSTB();
}

void ballmovement::updateRtoL(Entity crates[], int numCrates) {
    xposB -= xspeedB; // Move the ball to the left

    if (xposB < 0 ) { // Check if the ball has gone off the screen (example value, adjust as needed)
        xposB = 604; // Reset xposB to the right edge
    }
    checkCollisionRtoL(crates, numCrates);
}

void ballmovement::checkCollisionLtoR(Entity crates[], int numCrates) {
    SDL_Rect ballRect = {static_cast<int>(xposB), static_cast<int>(yposB), getCurrentFrameB().w * 2, getCurrentFrameB().h * 2};

    for (int i = 0; i < numCrates; i++) {
        if (Collision::checkCollision(ballRect, crates[i].GetNotptrDSTE())) {
            // Revert movement if collision detected
            xposB = 30;
            break;
        }
    }
}

void ballmovement::checkCollisionRtoL(Entity crates[], int numCrates) {
    SDL_Rect ballRect = {static_cast<int>(xposB), static_cast<int>(yposB), getCurrentFrameB().w * 2, getCurrentFrameB().h * 2};

    for (int i = 0; i < numCrates; i++) {
        if (Collision::checkCollision(ballRect, crates[i].GetNotptrDSTE())) {
            // Revert movement if collision detected
            xposB = 604;
            break;
        }
    }
}

/*void ballmovement::updateLtoR(Entity crates[], int numCrates, MyCharacter &character) {
    SDL_Rect charRect = *character.rtunDSTMC(); // Get the current position of MyCharacter
    float charX = charRect.x;
    float charY = charRect.y;

    float dx = charX - xposB; // Calculate the difference in x positions
    float dy = charY - yposB; // Calculate the difference in y positions
    float distance = std::sqrt(dx * dx + dy * dy); // Calculate the distance to MyCharacter
    double angle = std::atan2(dx,dy);
    double radians = angle * M_PI / 180.0; // Convert to radians

    // Normalize the direction and scale by the ball's speed
    xposB = xspeedB;
    yposB = yspeedB;

    checkCollisionLtoR(crates, numCrates);
}

*/
