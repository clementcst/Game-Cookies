    #include "Miscellanous.h"
    #include "Display.h"
    #include "Movements.h"
    #include "InitGame.h"
    #include "ManageFiles.h"

    int main(void)
    {
        EditTerminal();
        InitRNG();
        
        float float_diffRate = ChooseDifficulty();
        int int_mapSize = ChooseMapSize();
        
        PlayerInfo s_playerInfo = SetupPlayer(); 
        InitEnergy(&s_playerInfo, int_mapSize);
        
        List* p_listpath = InitList(s_playerInfo.coordonnees);
       
        int** matrice_Map = InitMap(int_mapSize, 
                                    float_diffRate,
                                    &s_playerInfo);
        int*** matrice_Distance = InitDistance(int_mapSize);
        
        char * MapString = AllocMapString(int_mapSize);
        char * DistanceString = AllocDistanceString(int_mapSize);
        
        DisplayMap(matrice_Map, int_mapSize);
        //DebugDisplayMatriceDistance(int_mapSize, matrice_Distance);
        printf("Votre energie : %d\n",s_playerInfo.energy);
        ShowKeyAvailable(&s_playerInfo, matrice_Distance);


//TESTS DE SAUVEGARDE
    MatriceMapToString(matrice_Map, int_mapSize, MapString);
    
    //printf("\n\nMap_string 1 = %s\n\n\n", MapString);

    MatriceDistanceToString(matrice_Distance, int_mapSize, DistanceString);
    StockCurrentTurn(MapString, DistanceString, &s_playerInfo);

    //printf("\n\nMap_string 2 = %s\n\n\n", MapString);

    GetAllInfo(MapString, DistanceString, &s_playerInfo, int_mapSize);
        
//TESTS DE RECUPERATION DE SAUVEGARDE
    StringToMatriceMap(MapString, int_mapSize, matrice_Map);
    StringToMatriceDistance(DistanceString, int_mapSize, matrice_Distance);

//FIN DES TESTS
        
        
        int bool_victory = Game(int_mapSize, matrice_Map, matrice_Distance,&s_playerInfo, p_listpath);
        // DebugDisplayMap(matrice_Map, int_mapSize);  

        SupprFile(CURRENT_GAME_CSV);
        free(MapString);
        free(DistanceString);
        PrintList(p_listpath);
        FreeList(p_listpath);
        UnallocMatriceMap(matrice_Map, int_mapSize);
        UnallocMatriceDistance(matrice_Distance, int_mapSize);
        return 0;
    }
