#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define WIDTH 80 //max for 15" is 166 X
#define HEIGHT 20 //max for 15" is 30 Y
#define POPULATION 5
#define MAX_LAKES 10
#define MAX_MOUNTAINS 10
#define MAX_WOODS 10
#define MAX_LAKES_RAY 6
#define MAX_MOUNTAINS_RAY 6
#define MAX_WOODS_RAY 6

/*ATTENZIONE! Settata a 0 premi invio per avanzare, altrimenti avanza ogni secondo*/
#define AUTO 0

/*Se AUTO attivata, definisci i secondi di pausa tra un timestep e l'altro*/
#define SPEED 1

/*Variabili relative alla mappa*/
#define MAP_ISLAND 0

/*Variabile enabling/disabling DEBUG*/
#define PATH_DEBUG 0

#endif
