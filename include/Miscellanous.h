#ifndef MISCELLANOUS_H
#define MISCELLANOUS_H
    #define square(a)  (a)*(a)
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>
    #include <time.h>
    #include <string.h>
    #include <time.h>   

    typedef struct coordonnees coordonnees;
    struct coordonnees{ // Structure contenant des coordonnées 
        int x;
        int y;
    };

    typedef struct Node{ // enregistre les coordonnées dans une list 
        coordonnees coordonnees;
        struct Node *next;
    } Node;

    typedef struct List{
        Node* firstnode;
    } List;
    

    typedef struct PlayerInfo PlayerInfo; 
    struct PlayerInfo{ // Structure contennant les informations du joueur
        coordonnees coordonnees;
        int energy;
        int distance;
        int gain_energy;
        int lost_energy;
        int backward;
    };

    int RNG(int min, int max);

    int CoordCompare(int** matrice_map, int int_x, int int_y, char constant_rep);

    int CoordCompare2(int** matrice_map, coordonnees coord, char constant_rep);

    int IsBetween(int int_Comp, int int_min, int int_max);

    void printf_center(const char* str);

    void InitRNG();

    coordonnees ModifCoord(coordonnees coord, int int_x, int int_y);
    
     Node* CreateNode(coordonnees coord, int bonus);

    List* InitList(coordonnees coord);

    void AddNode(List* p_list, coordonnees coord, int bonus);

    void RemoveNode(List* p_list);

    long LengthList(List *p_list);

    void GetfirstNode(List* p_list, int* p_last_x, int* p_last_y, int* is_bonus);
    
    void FreeList(List* p_list);

    int IsInList(List* p_list, coordonnees coord);

    int DefineStartPlayer(PlayerInfo* p_playerInfo, int int_mapSize);

#endif
