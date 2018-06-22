#include <iostream>
#include <unistd.h>
#include <vector>
#include "classes/Vision.h"
#include "classes/ModularArm.h"
#include "classes/SOMBracoModular.h"

using namespace std;

int main(){
    Vision vision;
    vision.start();

    ModularArm arm;
    arm.start();

    vector<vector<vector<double>>> matrixVector = {
 { {97, 129, 362, 346},  {98, 130, 368, 337},  {100, 131, 371, 326},  {103, 131, 374, 312},  {106, 130, 376, 296},  {109, 129, 376, 280},  {113, 128, 376, 260},  {117, 129, 377, 239},  {120, 128, 376, 221},  {123, 129, 374, 205},  {125, 129, 372, 191},  {127, 129, 370, 176},  {130, 130, 367, 161},  {132, 130, 362, 147},  {134, 130, 358, 134} },
 { {97, 129, 363, 348},  {98, 129, 365, 341},  {100, 129, 368, 329},  {103, 129, 370, 314},  {106, 128, 372, 299},  {110, 127, 372, 282},  {114, 126, 373, 261},  {117, 126, 373, 242},  {120, 127, 373, 224},  {123, 127, 372, 209},  {125, 127, 370, 194},  {127, 128, 369, 180},  {130, 129, 366, 165},  {132, 128, 361, 152},  {134, 128, 357, 140} },
 { {96, 129, 361, 354},  {97, 128, 361, 347},  {100, 127, 363, 334},  {104, 126, 366, 318},  {107, 125, 367, 302},  {110, 124, 367, 285},  {114, 123, 368, 265},  {118, 123, 369, 246},  {120, 124, 370, 229},  {123, 125, 370, 213},  {125, 126, 369, 200},  {128, 125, 365, 185},  {130, 125, 362, 170},  {132, 126, 359, 157},  {134, 126, 356, 148} },
 { {95, 129, 358, 361},  {97, 127, 358, 352},  {100, 124, 358, 340},  {104, 123, 360, 324},  {107, 121, 361, 307},  {111, 120, 362, 290},  {114, 119, 362, 271},  {118, 120, 363, 253},  {120, 121, 365, 235},  {122, 123, 366, 220},  {125, 122, 363, 206},  {128, 121, 359, 192},  {131, 121, 356, 177},  {132, 122, 355, 165},  {134, 121, 352, 159} },
 { {94, 128, 354, 367},  {96, 125, 354, 358},  {100, 122, 353, 345},  {103, 120, 354, 330},  {107, 118, 354, 313},  {110, 117, 355, 297},  {114, 116, 356, 279},  {117, 116, 357, 263},  {120, 117, 358, 245},  {123, 117, 358, 228},  {126, 116, 356, 214},  {129, 115, 352, 201},  {131, 115, 349, 189},  {133, 115, 346, 179},  {135, 114, 344, 173} },
 { {92, 127, 349, 375},  {96, 123, 348, 364},  {99, 120, 347, 351},  {103, 117, 346, 337},  {107, 115, 347, 321},  {110, 114, 348, 306},  {113, 113, 350, 289},  {117, 113, 350, 273},  {120, 113, 351, 255},  {123, 113, 351, 237},  {127, 111, 348, 222},  {130, 110, 344, 211},  {132, 108, 340, 201},  {134, 107, 336, 193},  {135, 107, 334, 186} },
 { {93, 122, 340, 379},  {95, 119, 339, 370},  {99, 116, 338, 358},  {102, 113, 337, 345},  {106, 111, 338, 331},  {109, 110, 339, 317},  {112, 109, 340, 301},  {116, 108, 341, 285},  {119, 108, 342, 267},  {123, 107, 342, 248},  {126, 107, 340, 233},  {130, 105, 336, 220},  {133, 103, 331, 210},  {135, 101, 326, 204},  {136, 100, 325, 198} },
 { {93, 117, 329, 383},  {96, 114, 328, 375},  {99, 111, 328, 364},  {102, 109, 327, 352},  {105, 107, 328, 340},  {108, 106, 329, 328},  {111, 104, 330, 313},  {115, 103, 331, 297},  {118, 103, 331, 279},  {122, 102, 332, 261},  {126, 102, 331, 245},  {129, 100, 328, 231},  {132, 98, 324, 221},  {134, 97, 320, 214},  {136, 95, 317, 209} },
 { {94, 111, 317, 388},  {96, 109, 316, 380},  {98, 106, 316, 370},  {101, 104, 316, 359},  {104, 102, 317, 349},  {107, 101, 318, 337},  {110, 100, 319, 322},  {114, 99, 320, 306},  {118, 98, 321, 289},  {122, 97, 322, 272},  {125, 97, 322, 256},  {128, 96, 320, 243},  {131, 95, 318, 232},  {133, 93, 314, 225},  {135, 92, 312, 219} },
 { {93, 106, 303, 393},  {95, 104, 303, 385},  {98, 101, 303, 376},  {101, 99, 304, 366},  {103, 98, 304, 356},  {106, 97, 306, 345},  {110, 95, 307, 330},  {113, 94, 309, 314},  {117, 93, 311, 298},  {121, 93, 312, 281},  {124, 93, 313, 263},  {127, 92, 312, 253},  {130, 91, 310, 244},  {132, 90, 307, 235},  {134, 88, 305, 228} },
 { {94, 100, 291, 395},  {95, 99, 291, 390},  {98, 97, 291, 380},  {100, 95, 292, 370},  {103, 93, 293, 361},  {106, 92, 295, 350},  {109, 91, 296, 336},  {113, 90, 298, 321},  {117, 89, 300, 305},  {120, 89, 303, 289},  {123, 89, 304, 275},  {126, 88, 303, 264},  {129, 87, 302, 253},  {131, 86, 301, 245},  {133, 85, 299, 238} },
 { {94, 94, 278, 394},  {96, 93, 278, 389},  {98, 91, 278, 382},  {100, 90, 280, 373},  {103, 89, 282, 364},  {105, 88, 284, 355},  {108, 87, 286, 342},  {112, 86, 288, 327},  {116, 85, 290, 313},  {119, 85, 293, 298},  {123, 84, 294, 284},  {126, 84, 294, 272},  {129, 83, 294, 261},  {131, 82, 292, 252},  {133, 82, 291, 245} },
 { {95, 89, 265, 394},  {96, 87, 264, 389},  {98, 87, 267, 383},  {100, 86, 269, 375},  {102, 85, 272, 367},  {105, 84, 275, 356},  {109, 83, 278, 343},  {112, 82, 280, 330},  {115, 82, 283, 317},  {119, 81, 285, 303},  {122, 81, 286, 290},  {126, 80, 286, 277},  {129, 79, 286, 266},  {131, 79, 285, 258},  {133, 78, 284, 249} },
 { {95, 84, 253, 394},  {96, 82, 251, 390},  {98, 82, 255, 383},  {100, 82, 260, 376},  {102, 81, 260, 369},  {105, 81, 266, 357},  {109, 80, 271, 343},  {113, 80, 274, 330},  {116, 79, 277, 317},  {119, 78, 278, 305},  {123, 78, 280, 292},  {126, 77, 280, 280},  {128, 77, 280, 269},  {131, 76, 279, 261},  {133, 76, 279, 252} },
 { {95, 80, 244, 393},  {96, 80, 245, 389},  {98, 79, 249, 382},  {101, 79, 253, 374},  {103, 79, 256, 366},  {106, 78, 261, 355},  {110, 77, 265, 342},  {113, 77, 269, 330},  {116, 77, 272, 318},  {120, 77, 275, 304},  {123, 76, 275, 292},  {126, 75, 275, 282},  {128, 75, 275, 272},  {131, 75, 275, 263},  {132, 75, 276, 256} }
}; 



    SOMModulaArm som(matrixVector,15,4,2,3);

    int joint[2] = {1,2};
    double input[4] = {0,0,340,400};
    double output[4];
    std::cout << "ALVO:  " << input[2] << " " << input[3] << std::endl;

    som.bestResponse(input, output);
    std::cout << "ANGULO SOM:   " << (int)output[0] << " " << (int)output[1] << std::endl;

    int x,y;
    arm.sendMoveMulti(output, joint , 2);    
    vision.getVisualPosition(x,y);
    std::cout << "IMAGE: " << x << " " << y << std::endl; 

    return 0;
}