#pragma once
#include "Action.h"
#include "Options.h"
//#include 'Options.h'




template <class T1, class T2> bool isIntersecting(T1& A, T2& B) {

    return A.right() >= B.left() && A.left() <= B.right()
        && A.bottom() >= B.top() && A.top() <= B.bottom();
}

//return true if two or more object are interecting
bool collisionTest(Pawn& player, Ball& ball2) {

    if (!isIntersecting(player, ball2)) {
        return false;
    }
    else {


        player.destroy();
        return true;
    }


}

//return true if two or more object are intersecting
bool collisionTest(Pawn& player, Meta& meta) {

    if (!isIntersecting(player, meta)) {
        return false;
    }
    else {

        player.destroy();
        return true;
    }


}


void Action:: MainMenu_draw(sf::RenderWindow &window, int &check,sf::Event &event, Menu &menu) {

    menu.draw(window);
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code) {
            case sf::Keyboard::Up:
                menu.MoveUp();
                break;
            case sf::Keyboard::Down:
                menu.MoveDown();
                break;

            case sf::Keyboard::Enter:
                switch (menu.GetPressedItem())
                {
                case 0:
                    std::cout << "PLAY\n";
                    check = 1;

                    break;
                case 1:
                    check = 2;
                    window.clear(sf::Color::Black);

                    std::cout << "OPTIONS\n";
                    //menu.close(window);

                    break;
                case 2:
                    window.close();
                    exit(0);
                    break;

                }

            }
            break;
        }
    }

}

void Action::Game_draw(sf::RenderWindow &window,Ball &ball,Ball &ball2,Ball &ball3,Ball &ball4,Ball &ball5,Ball &ball6,Pawn &player,Meta &meta,End_menu &the_end2,int &check) {
    ball.update();
    ball2.update();
    ball3.update();
    ball4.update();
    ball5.update();
    ball6.update();
    player.update();

    //ALL elements will be drawn
    window.draw(meta);
    window.draw(ball);
    window.draw(ball2);
    window.draw(ball3);
    window.draw(ball4);
    window.draw(ball5);
    window.draw(ball6);
    window.draw(player);




    //if press ESC game will be closed.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        exit(0);
    }

    if (collisionTest(player, ball)) {
        the_end2.set_finish(false);
        check = 8;
    }
    if (collisionTest(player, ball2)) {
        the_end2.set_finish(false);
        check = 8;
    }

    if (collisionTest(player, ball3)) {
        the_end2.set_finish(false);
        check = 8;
    }


    if (collisionTest(player, ball4)) {
        the_end2.set_finish(false);
        check = 8;
    }
    if (collisionTest(player, ball5)) {
        the_end2.set_finish(false);
        check = 8;
    }

    if (collisionTest(player, ball6)) {
        the_end2.set_finish(false);
        check = 8;
    }


    if (collisionTest(player, meta)) {
        check = 8;
        the_end2.set_finish(true);
    }
}




void Action::Options_menu(sf::RenderWindow &window,sf::Event &event,int &check,Options &options) {

    window.draw(options);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        exit(0);
    }
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code) {
            case sf::Keyboard::Up:
                options.MoveUp();
                break;
            case sf::Keyboard::Down:
                options.MoveDown();
                break;

            case sf::Keyboard::Enter:
                switch (options.GetPressedItem())
                {
                case 0:
                    std::cout << "DIFFICULT LEVEL\n";
                    check = 4;

                    break;
                case 1:
                    std::cout << "MUSIC\n";
                    check = 5;
                    break;
                case 2:
                    std::cout << "PLAYER COLOR\n";
                    check = 6;
                    break;

                case 3:
                    std::cout << "BACK\n";
                    check = 0;
                    break;

                case 4:
                    std::cout << "EXIT\n";
                    window.close();
                    exit(0);
                    break;
                }
            }
            break;
        }
    }

}

void Action:: Display_level(sf::RenderWindow &window,Ball &ball,Ball &ball2,Ball &ball3,Ball &ball4,Ball &ball5,Ball &ball6,sf::Event event,Level_menu &finish, std::vector<std::vector<int>> &level_hard, std::vector<std::vector<int>> &level_medium, std::vector<std::vector<int>> &level_easy, int &check) {
    window.draw(finish);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        exit(0);
    }
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code) {
            case sf::Keyboard::Left:
                finish.MoveLeft();
                break;
            case sf::Keyboard::Right:
                finish.MoveRight();
                break;

            case sf::Keyboard::Enter:
                switch (finish.GetPressedItem())
                {
                case 0:
                    std::cout << "EASY\n";
                    //Set the dificult level as easy
                    ball.change_level(level_easy[2][0], level_easy[2][1]);
                    ball2.change_level(level_easy[1][0], level_easy[1][1]);
                    ball3.change_level(level_easy[0][0], level_easy[0][1]);
                    ball4.change_level(level_easy[2][0], level_easy[2][1]);
                    ball5.change_level(level_easy[1][0], level_easy[1][1]);
                    ball6.change_level(level_easy[0][0], level_easy[0][1]);

                    break;
                case 1:



                    std::cout << "MEDIUM\n";
                    //set the dificult level as MEDIUM
                    ball.change_level(level_medium[2][0], level_medium[2][1]);
                    ball2.change_level(level_medium[1][0], level_medium[1][1]);
                    ball3.change_level(level_medium[0][0], level_medium[0][1]);
                    ball4.change_level(level_medium[2][0], level_medium[2][1]);
                    ball5.change_level(level_medium[1][0], level_medium[1][1]);
                    ball6.change_level(level_medium[0][0], level_medium[0][1]);


                    break;
                case 2:
                    std::cout << "HARD\n";
                    //Set the difficult level as EASY
                    ball.change_level(level_hard[2][0], level_hard[2][1]);
                    ball2.change_level(level_hard[1][0], level_hard[1][1]);
                    ball3.change_level(level_hard[0][0], level_hard[0][1]);
                    ball4.change_level(level_hard[2][0], level_hard[2][1]);
                    ball5.change_level(level_hard[1][0], level_hard[1][1]);
                    ball6.change_level(level_hard[0][0], level_hard[0][1]);
                    break;

                case 3:
                    std::cout << "BACK\n";
                    check = 2;
                    break;
                }
            }
            break;
        }
    }




}

void Action::Music_set(sf::RenderWindow &window,sf::Event &event, int &check,std::string &a,Music_choise_menu &music_choise,std::vector<std::string> &utwory, sf::Music &music ) {

    
        window.draw(music_choise);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            exit(0);
        }
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    music_choise.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    music_choise.MoveDown();
                    break;

                case sf::Keyboard::Enter:
                    switch (music_choise.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Podklad\n";
                        music.stop();
                        a = utwory[0];
                        if (!music.openFromFile(a)) {
                            std::cout << "ERROR\n";
                        }
                        music.play();
                        break;
                    case 1:

                        std::cout << "My_Doorbell\n";
                        music.stop();
                        a = utwory[1];
                        if (!music.openFromFile(a)) {
                            std::cout << "ERROR\n";
                        }
                        music.play();

                        break;
                    case 2:
                        std::cout << "Hardest_Button\n";
                        music.stop();
                        a = utwory[2];

                        if (!music.openFromFile(a)) {
                            std::cout << "ERROR\n";
                        }
                        music.play();
                        break;

                    case 3:
                        std::cout << "BACK\n";
                        check = 2;
                        break;
                    }
                }
                break;
            }
        }

}

void Action::Color_set_menu(sf::RenderWindow &window, sf::Event &event,Pawn &player,int &check,Color_Menu &color) {
    window.draw(color);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        exit(0);
    }
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code) {
            case sf::Keyboard::Left:
                color.MoveLeft();
                break;
            case sf::Keyboard::Right:
                color.MoveRight();
                break;

            case sf::Keyboard::Enter:
                switch (color.GetPressedItem())
                {
                case 0:
                    std::cout << "Blue\n";
                    player.change_color(sf::Color::Blue);

                    break;
                case 1:
                    std::cout << "Yellow\n";
                    player.change_color(sf::Color::Yellow);


                    break;
                case 2:
                    std::cout << "Green\n";
                    player.change_color(sf::Color::Green);

                    break;

                case 3:
                    std::cout << "BACK\n";
                    check = 2;
                    break;
                }
            }
            break;
        }
    }


}

void Action::Exit_menu(sf::RenderWindow &window, Pawn &player, int &check, sf::Event &event,End_menu &the_end2) {

    window.draw(the_end2);
    player.position();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        exit(0);
    }
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code) {
            case sf::Keyboard::Left:
                the_end2.MoveLeft();
                break;
            case sf::Keyboard::Right:
                the_end2.MoveRight();
                break;

            case sf::Keyboard::Enter:
                switch (the_end2.GetPressedItem())
                {
                case 1:
                    std::cout << "Main Menu\n";
                    check = 0;

                    break;
                case 2:


                    window.close();
                    exit(0);
                    std::cout << "Exit\n";
                    ;


                    break;

                }

            }
            break;
        }
    }

}