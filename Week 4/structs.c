#include <stdio.h>

// pew muss noch korrekt eingebunden werden
// ab drink health potion

typedef struct Gun{
    unsigned int ammo;
    unsigned int clipSize;
    unsigned int clipAmmo;
    unsigned int damage;
} Gun;

typedef struct Player{
    unsigned int health;
    int shield;
    Gun weapon;
    unsigned int money;
} Player;

typedef struct ShootingParty{
    Player attacker;
    Player defender;
} ShootingParty;

typedef struct Potion {
    unsigned int amount;
}Potion;

typedef struct Person {
    int money;
} Person;

typedef struct Family {
    Person mom;
    Person dad;
    Person kid;
}Family;


int howOftenCanIReload(Gun weapon){
    unsigned int result = (weapon.ammo - weapon.clipAmmo) / weapon.clipSize;
    return result;
}

int reload(Gun weapon){
    weapon.ammo -= weapon.clipSize - weapon.clipAmmo;
}

Gun pew (Gun weapon){
    if(weapon.clipAmmo == 0){
        printf("You need to reload! \n");
        return weapon;
    }else{
        weapon.clipAmmo--;
        return weapon;
    }
}

Player drinkPotion(Player player, Potion potion){
    player.health += potion.amount;
    return player;
}


ShootingParty calculateDmg(ShootingParty shootingParty){
    shootingParty.defender.shield -= shootingParty.attacker.weapon.damage;
    shootingParty.attacker.weapon.clipAmmo--;
    if(shootingParty.defender.shield < 0){
        shootingParty.defender.health += shootingParty.defender.shield;
        shootingParty.defender.shield = 0;
    }
    return shootingParty;
}

Person buyUselessSkin(Person dad){
    dad.money -= 20;
    return dad;
}





int main(void){
    Gun pistol;
    pistol.ammo = 125;
    pistol.clipAmmo = 12;
    pistol.clipSize = 12;
    pistol.damage = 1;

    printf("Current Ammo in Clip: %i \n", pistol.clipAmmo);
    pistol = pew(pistol);
    printf("Current Ammo in Clip: %i \n", pistol.clipAmmo);
    howOftenCanIReload(pistol);
    printf("How often can i reload?: %i \n", howOftenCanIReload(pistol));

    Gun machineGun = {100, 25, 25, 22};
    Player peter = {100, 50, machineGun};

    Player dominik = {100, 50, machineGun};

    
    ShootingParty party = {peter, dominik};
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik\n");
    party = calculateDmg(party);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");
    party = calculateDmg(party);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");
    party = calculateDmg(party);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");
    party = calculateDmg(party);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n" , party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");
}