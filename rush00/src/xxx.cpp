// Test main.

#include "Bullet.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "GameObject.hpp"
#include "Header.hpp"

int main() {

    Player p = Player();

    std::cout << "X/Y: " << p.getPosX() << p.getPosY() << "\nDirection: " << p.getDirection() << "\nLives: " << p.getLives()
    << "\nHP: " << p.getHP() << "\nATK dmg: " << p.getAtkDmg() << "\nBullet SPD: " << p.getBulletSpeed() << std::endl;

    std::cout << "Bullet status:\n";

    for (int i = 0; i < MAX_BULLETS; i++) {
        std::cout << i << ": " << p.getBullet(i)->getAliveStatus() << std::endl;
    }


    p.takeDamage(1);
    p.takeDamage(1);
    p.takeDamage(1);
    
    Enemy s = EnScrub(20);

}
