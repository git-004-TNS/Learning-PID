#include <iostream>
#define DESIRED_POSITION 50

using namespace std;


void actuate(float* t, float ts, float* player_position, float velocity);


void print_status(float t, float player_position);
float getError(float curr_postion);



int main()
{
    //Variables

    //Time
    float t = 0;                  //time
    float ts = 0.01;               //time step

    //Player
    float player_position = 0;    //player position
    float vel = 1;                //player velocity

    float desired_position = 50; //desiredPosition


    //Control Parameter:
    float K_p = 0.5;
    float t_max = 10;
    /*
    cout << "Before actuation: ";
    print_status(player_position);

    actuate(&t, ts, &player_position, 2);

    cout << "After Actuation:";
    print_status(player_position);

    cout << "Error: " << getError(player_position) << endl;

    actuate(&t, ts, &player_position, 20);

    print_status(player_position);
    cout << "Error: " << getError(player_position) << endl;
*/

    //Controller.

    //give the actuating signal



//P controller
    while(t < t_max){
      //print_status(t, player_position);
      actuate(&t, ts, &player_position, K_p*getError(player_position));
    }

    //Comparing for different K_p's:

    for(K_p = 0.1; K_p < 1; K_p+=0.1)
    {

    t = 0;
    player_position = 0;

         while(t < t_max){
      //print_status(t, player_position);
      actuate(&t, ts, &player_position, K_p*getError(player_position));
    }

    cout << "K_p: " << K_p << endl;
    print_status(t, player_position);

    printf("\nK_p: %f \t Error: %f\n", K_p, getError(player_position));

    }


    cout << ts;


}

void print_status(float t, float player_position)
{
    cout << "\n\tt: " << t << "\t" << "pos: " << player_position  << endl;
}



void actuate(float *t, float ts, float* player_position, float velocity)  //Receives the actuating signal, the velocity and actuates (moves the player) according to it.
{
    *player_position = *player_position + velocity*ts;
    *t = *t + ts;
}

float getError(float curr_position)
{
    return (DESIRED_POSITION - curr_position);
}

