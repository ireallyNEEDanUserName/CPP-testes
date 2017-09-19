//-------------------------------MOB Pac-Man------------------------
//Passar o mapa e as coordenadas do player como argumentos da função.
//Fazer: acrescentar mais de um mob, e um timer para movimentos.
//igorar random quando achou player, utilizar bool.


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

//valores da movimentação do Mob
enum acao{
FRENTE_MIN = 0,
FRENTE_MAX = 3,

TRAS_MIN = 4,
TRAS_MAX = 7,

BAIXO_MIN = 8,
BAIXO_MAX = 10,

CIMA_MIN = 11,
CIMA_MAX = 15
};

//verificar a quantidade de vezes que é rodado o loop do mob e em qual direção.
int loopVencXpos = 0, loopVencXneg = 0, loopVencX = 0, loopVencYpos = 0, loopVencYneg = 0, loopVencY = 0, loop = 0; 

//variavel para ganhar o jogo e mover o mob.
bool ganhar = false, seMover = false;

//coordenadas do mob
int mobCoordX = 8;
int mobCoordY = 11;

//coordenadas do player
int coordX = 3;
int coordY = 16;

int main(){

int map[12][21] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4},
{4,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,4},
{4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,4},
{4,0,0,0,0,1,1,1,4,0,0,0,0,1,1,1,1,1,1,1,4},
{4,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,0,0,4},
{4,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,0,0,4},
{4,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,4,1,4},
{4,1,1,1,1,1,1,1,4,1,1,5,4,1,1,1,1,1,1,1,4},
{4,1,1,1,4,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,4},
{4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4},
{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
};

int moverMob = 0; //variavel para jogar o random do mob.
int randMin = 0, randMax = 15; //variaveis para limitar os valores do random do mob.
int distX = 0, distY = 0; //variaveis para calcular a distancia do mob e do player.

string direcaoX = " ", direcaoY = " "; //verificar qual o sentido que deve seguir.

srand (time(NULL));

while(!ganhar){
	//verificar a distancia e o sentido em que esta o player em relação ao mob.
	if(mobCoordX < coordX){
		distX = coordX - mobCoordX; direcaoX = "Positivo";
	}else if(mobCoordX >= coordX){
		 distX = mobCoordX - coordX; direcaoX = "Negativo";
	}
	
	if(mobCoordY < coordY){
		 distY = coordY - mobCoordY; direcaoY = "Positivo";
	}else if(mobCoordY >= coordY){
		 distY = mobCoordY - coordY; direcaoY = "Negativo";
	}
	
	//seguir o player até acha-lo.
	if(distX <= 3 && distY <= 3){
		if(distY == 0 && distX != 0){
			if(direcaoX == "Positivo"){
				randMin = 8; 
				randMax = 3;
			}else if(direcaoX == "Negativo"){
				randMin = 10; 
				randMax = 5;
			}
		}else if(distX == 0 && distY != 0){
			if(direcaoY == "Positivo"){
				randMin = 0; 
				randMax = 4;
			}else if(direcaoY == "Negativo"){
				randMin = 3; 
				randMax = 4;
			}
		}else if(distX == 0 && distY == 0){
		ganhar = true;
		seMover = true;
		cout<<"GAME OVER!! HAHAH.";
		}
	}else if(loop%2 == 0){ //mover o mob randomicamente.
		int yPos = 0, yNeg = 0, y = 0, xPos = 0, xNeg = 0, x = 0;
		for(int AI = 1; AI<=4; AI++){
			if(map[mobCoordX][mobCoordY + AI] != 0 && map[mobCoordX][mobCoordY + AI] != 4 && map[mobCoordX][mobCoordY + AI] != 5) yPos++;
			if(map[mobCoordX][mobCoordY - AI] != 0 && map[mobCoordX][mobCoordY - AI] != 4 && map[mobCoordX][mobCoordY - AI] != 5) yNeg++;

			if(map[mobCoordX + AI][mobCoordY] != 0 && map[mobCoordX + AI][mobCoordY] != 4 && map[mobCoordX + AI][mobCoordY] != 5) xPos++;
			if(map[mobCoordX - AI][mobCoordY] != 0 && map[mobCoordX - AI][mobCoordY] != 4 && map[mobCoordX - AI][mobCoordY] != 5) xNeg++;
		}
		y = yPos + yNeg;
		x = xPos + xNeg;
		
		if(loopVencXpos > 0) xPos += loopVencXpos;
		else if(loopVencXneg > 0) xNeg += loopVencXneg;
		else if(loopVencYpos > 0) yPos += loopVencYpos;
		else if(loopVencYneg > 0) yNeg += loopVencYneg;
		
		loopVencX = loopVencXpos + loopVencXneg;
		loopVencY = loopVencYpos + loopVencYneg;
		
		if(x > y && loopVencX < 5){
			if(xPos > xNeg){
				randMin = 8; 
				randMax = 3;
				cout<<"\nxPos";
				loopVencXpos++;
				loopVencXneg = 0;
			}else{
				randMin = 10; 
				randMax = 5;
				cout<<"\nxNeg";
				loopVencXneg++;
				loopVencXpos = 0;
			}
			loopVencYpos = 0;
			loopVencYneg = 0;
		}else if(y > x && loopVencY < 10){
			if(yPos > yNeg){
				randMin = 0; 
				randMax = 4;
				cout<<"\nyPos";
				loopVencYpos++;
				loopVencYneg = 0;
			}else{
				randMin = 3; 
				randMax = 4;
				cout<<"\nyNeg";
				loopVencYneg++;
				loopVencYpos = 0;
			}
			loopVencXpos = 0;
			loopVencXneg = 0;
		}else{
			randMin = 0;
			randMax = 15;
			loopVencXpos = 0;
			loopVencXneg = 0;
			loopVencYpos = 0;
			loopVencYneg = 0;
			cout << endl;
		}
		cout<<" x: "<<x<<" y: "<<y<<endl;
	}

	moverMob = rand() % randMax + randMin; //random que indica direção que o mob vai seguir.
	
	if(!seMover){
	
		if(moverMob >= FRENTE_MIN && moverMob <= FRENTE_MAX){
			if(mobCoordY >= 20 && map[mobCoordX][mobCoordY - 1] != 0 && map[mobCoordX][mobCoordY - 1] != 4 && map[mobCoordX][mobCoordY - 1] != 5){
				mobCoordY--;
			}else if(map[mobCoordX][mobCoordY + 1] != 0 && map[mobCoordX][mobCoordY + 1] != 4 && map[mobCoordX][mobCoordY + 1] != 5){
				mobCoordY++;
			}else if(map[mobCoordX][mobCoordY - 1] != 0 && map[mobCoordX][mobCoordY - 1] != 4 && map[mobCoordX][mobCoordY - 1] != 5){
				mobCoordY--;
			}
		}else if(moverMob >= TRAS_MIN && moverMob <= TRAS_MAX){
			if(mobCoordY <= 1 && map[mobCoordX][mobCoordY + 1] != 0 && map[mobCoordX][mobCoordY + 1] != 4 && map[mobCoordX][mobCoordY + 1] != 5){
				mobCoordY++;
			}else if(map[mobCoordX][(mobCoordY - 1)] != 0 && map[mobCoordX][(mobCoordY - 1)] != 4 && map[mobCoordX][mobCoordY - 1] != 5){
				mobCoordY--;
			}else if(map[mobCoordX][mobCoordY + 1] != 0 && map[mobCoordX][mobCoordY + 1] != 4 && map[mobCoordX][mobCoordY + 1] != 5){
				mobCoordY++;
			}
		}else if(moverMob >= BAIXO_MIN && moverMob <= BAIXO_MAX){
			if(mobCoordX >= 10 && map[mobCoordX - 1][mobCoordY] != 0 && map[mobCoordX - 1][mobCoordY] != 4 && map[mobCoordX - 1][mobCoordY] != 5){
				mobCoordX--;
			}else if(map[mobCoordX + 1][mobCoordY] != 0 && map[mobCoordX + 1][mobCoordY] != 4 && map[mobCoordX + 1][mobCoordY] != 5){
				mobCoordX++;
			}else if(map[mobCoordX - 1][mobCoordY] != 0 && map[mobCoordX - 1][mobCoordY] != 4 && map[mobCoordX - 1][mobCoordY] != 5){
				mobCoordX--;
			}
		}else if(moverMob >= CIMA_MIN && moverMob <= CIMA_MAX){
			if(mobCoordX <= 1 && map[(mobCoordX + 1)][mobCoordY] != 0 && map[(mobCoordX + 1)][mobCoordY] != 4 && map[mobCoordX + 1][mobCoordY] != 5){
				mobCoordX++;
			}else if(map[mobCoordX - 1][mobCoordY] != 0 && map[mobCoordX - 1][mobCoordY] != 4 && map[mobCoordX - 1][mobCoordY] != 5){
				mobCoordX--;
			}else if(map[(mobCoordX + 1)][mobCoordY] != 0 && map[(mobCoordX + 1)][mobCoordY] != 4 && map[mobCoordX + 1][mobCoordY] != 5){
				mobCoordX++;
			}
		}
	} 
	
	cout<<"loop: "<<loop<<" rand: "<<moverMob<<" X: "<<mobCoordX<<" Y: "<<mobCoordY;
	cout << endl;
	
	loop++; //repetições do movimento.

}
}