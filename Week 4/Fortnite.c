#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Gun{
    int ammo;
    int clip;
    int capacity;    
    int damage;
} Gun;

typedef struct Player{
    Gun g;
    int shield;
    int health;
    int id; // for identification
} Player;



int reloadTimes(Gun *g){
    return g->ammo /  g->capacity;
};

void reload(Gun *g){
    if(g->ammo <= 0){
        return;
    }
    int missing = g->capacity - g->clip;
    if(g->ammo < missing){
        g->clip += g->ammo;
        g->ammo = 0;
    } else{
        g->clip += missing;
        g->ammo -= missing;
    }
}

void pew(Player *p, Gun *g){
    if(g->clip <= 0){
        reload(g);
        printf("Player %i is reloading\n", p->id);
        if(g->clip <= 0){
            return;
        }
    }
    int damage = g->damage;
    if(p->shield >= damage){
        p->shield -= damage;
    } else if(p->shield > 0){
        damage = damage - p->shield;
        p->shield = 0;
        p->health -= damage;
        printf("Player %i lost their shield\n", p->id);
    } else{
        p->health -= damage;
    }
    if(p->shield > 0){
        printf("A gun did %i damage to Player %i and left %i shield and %i health\n", g->damage, p->id, p->shield, p->health);
    }else{
        printf("A gun did %i damage to Player %i and left %i health\n", g->damage, p->id, p->health);    
    }
}

void shieldDrink(Player *p){
    p->shield += 25;
    p->shield %= 100;
    printf("A player drank a shield drink and increased his shield to %i", p->shield);
}

void medKit(Player *p){
    p->health += 25;
    p->health %= 100;
    printf("A player used a MedKit and increased his health to %i", p->health);
}

void printGun(Gun *g){
    printf("Gun: Ammo: %i, Clip: %i, Max: %i, Dmg: %i\n",g->ammo, g->clip, g->capacity, g->damage);
}


typedef struct Person{
    int money;
} Person;

typedef struct Family{
    Person father;
    Person mother;
    Person fortnitePlayingKid;
} Family;

void buySkin(Family *f){
    f->father.money -= 20; //No 0 check because this is america. Get in debt for them sweet skins.
}

int rnd(int min, int max){
    return rand() % max + min;
}

int main(){
    srand(time(NULL)); //Seed the random number generator with system clock
    Gun player1Gun = {rnd(1, 150), rnd(1,25), rnd(1,25), rnd(1,100)/4};
    Gun player2Gun = {rnd(1, 150), rnd(1,25), rnd(1,25), rnd(1,100)/4};
    Player player1 = {player1Gun, 100, 100, 1};
    Player player2 = {player2Gun, 100, 100, 2};
    printGun(&player1Gun);
    printGun(&player2Gun);
    while(player1.health > 0 && player2.health > 0){
        pew(&player1, &(player2.g));
        pew(&player2, &(player1.g));
    }
    if(player1.health > 0 && player2.health <= 0){
        printf("Player 1 Victory Royale \n");
    }else if(player2.health > 0 && player1.health <= 0){
        printf("Player 2 Victory Royale \n");
    }else{
        printf("DRAW\n");
    }
    return 0; 
}