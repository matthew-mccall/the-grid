#include <time.h>

#include <ti/getcsc.h>
#include <graphx.h>
#include <keypadc.h>

#include "Player.hpp"

#include <Grid.hpp>

int main()
{
    clock_t lastTime = clock();
    clock_t currentTime = clock();
    clock_t deltaTime = 0;
    float timeInSeconds = 0;

    /* No rendering allowed! */
    Player player1;
    player1.moveTo({GFX_LCD_WIDTH / 2, GFX_LCD_HEIGHT / 2});
    player1.setDirection(Entity::Direction::UP);
    player1.setSpeed(20);
    player1.setColor(0x1f);

    Player player2;
    player2.moveTo({GFX_LCD_WIDTH / 2, GFX_LCD_HEIGHT / 2});
    player2.setDirection(Entity::Direction::DOWN);
    player2.setSpeed(20);
    player2.setColor(0xe2);

    const Grid grid { player1, player2 };

    /* Initialize graphics drawing */
    gfx_Begin();

    /* Draw to the buffer to avoid rendering artifacts */
    gfx_SetDrawBuffer();

    gfx_FillScreen(Grid::COLOR);
    gfx_SwapDraw();

    bool gameOver = false;

    while (!gameOver)
    {
        kb_Scan();

        if (kb_IsDown(kb_KeyClear)) {
          break;
        }

        if (kb_IsDown(kb_KeyUp)) {
            player1.setDirection(Entity::Direction::UP);
        } else if (kb_IsDown(kb_KeyRight)) {
            player1.setDirection(Entity::Direction::RIGHT);
        } else if (kb_IsDown(kb_KeyDown)) {
            player1.setDirection(Entity::Direction::DOWN);
        } else if (kb_IsDown(kb_KeyLeft)) {
            player1.setDirection(Entity::Direction::LEFT);
        }

        currentTime = clock();
        deltaTime = currentTime - lastTime;
        timeInSeconds = static_cast<float>(deltaTime) / CLOCKS_PER_SEC;
        lastTime = currentTime;

        /* Copy previous frame as a base for this frame */
        gfx_BlitScreen();

        grid.update(timeInSeconds);
        gameOver = grid.gameOver();

        /* As little non-rendering logic as possible */
        grid.draw();

        /* Queue the buffered frame to be displayed */
        gfx_SwapDraw();
    }

    while (!os_GetCSC()) {}

    /* End graphics drawing */
    gfx_End();

    return EXIT_SUCCESS;
}
