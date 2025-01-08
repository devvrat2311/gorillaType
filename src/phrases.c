#include "phrases.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DICTIONARY_SIZE 320
#define MAX_WORD_LENGTH 20

char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH] = {
    "hello ", "world ", "programming ", "challenge ", "keyboard ",
    "typing ", "speed ", "accuracy ", "practice ", "test ",
    "apple ", "orange ", "banana ", "grape ", "watermelon ",
    "pear ", "cherry ", "strawberry ", "blueberry ", "peach ",
    "carrot ", "potato ", "onion ", "garlic ", "tomato ",
    "cucumber ", "spinach ", "broccoli ", "lettuce ", "pepper ",
    "keyboard ", "monitor ", "mouse ", "printer ", "laptop ",
    "desktop ", "notebook ", "tablet ", "smartphone ", "headphone ",
    "teacher ", "student ", "classroom ", "blackboard ", "chalk ",
    "desk ", "chair ", "school ", "university ", "college ",
    "running ", "jumping ", "swimming ", "walking ", "cycling ",
    "programming ", "coding ", "debugging ", "testing ", "deploying ",
    "cat ", "dog ", "rabbit ", "bird ", "fish ",
    "elephant ", "tiger ", "lion ", "giraffe ", "zebra ",
    "mountain ", "valley ", "river ", "ocean ", "lake ",
    "cloud ", "rain ", "snow ", "storm ", "wind ",
    "book ", "novel ", "poem ", "story ", "essay ",
    "music ", "song ", "melody ", "rhythm ", "harmony ",
    "car ", "truck ", "bicycle ", "motorcycle ", "bus ",
    "train ", "plane ", "ship ", "boat ", "submarine ",
    "coffee ", "tea ", "milk ", "water ", "juice ",
    "bread ", "butter ", "cheese ", "honey ", "jam ",
    "galaxy ", "universe ", "planet ", "star ", "comet ",
    "asteroid ", "satellite ", "rocket ", "spaceship ", "cosmos ",
    "forest ", "tree ", "branch ", "leaf ", "flower ",
    "grass ", "bush ", "desert ", "jungle ", "savanna ",
    "emotion ", "happiness ", "sadness ", "anger ", "fear ",
    "joy ", "surprise ", "trust ", "disgust ", "curiosity ",
    "house ", "apartment ", "cottage ", "villa ", "skyscraper ",
    "roof ", "window ", "door ", "chimney ", "garage ",
    "bottle ", "glass ", "plate ", "cup ", "spoon ",
    "fork ", "knife ", "bowl ", "napkin ", "straw ",
    "camera ", "phone ", "television ", "radio ", "watch ",
    "clock ", "speaker ", "microphone ", "charger ", "battery ",
    "road ", "bridge ", "tunnel ", "highway ", "path ",
    "alley ", "sidewalk ", "intersection ", "crosswalk ", "streetlight ",
    "pencil ", "pen ", "eraser ", "sharpener ", "marker ",
    "crayon ", "paintbrush ", "canvas ", "palette ", "easel ",
    "violin ", "guitar ", "piano ", "drum ", "trumpet ",
    "flute ", "cello ", "harp ", "accordion ", "clarinet ",
    "health ", "doctor ", "nurse ", "patient ", "hospital ",
    "clinic ", "medicine ", "vaccine ", "surgery ", "treatment ",
    "soccer ", "basketball ", "tennis ", "volleyball ", "baseball ",
    "hockey ", "cricket ", "rugby ", "golf ", "badminton ",
    "sun ", "moon ", "earth ", "mercury ", "venus ",
    "mars ", "jupiter ", "saturn ", "uranus ", "neptune ",
    "algorithm ", "data ", "binary ", "loop ", "array ",
    "function ", "variable ", "constant ", "pointer ", "string ",
    "electricity ", "lightning ", "magnet ", "battery ", "voltage ",
    "current ", "circuit ", "resistor ", "capacitor ", "diode ",
    "fabric ", "cotton ", "silk ", "wool ", "polyester ",
    "leather ", "denim ", "linen ", "velvet ", "suede ",
    "castle ", "palace ", "fortress ", "tower ", "bridge ",
    "tavern ", "village ", "market ", "barn ", "dock ",
    "dolphin ", "shark ", "whale ", "octopus ", "seal ",
    "crab ", "lobster ", "shrimp ", "starfish ", "coral ",
    "cloudy ", "sunny ", "rainy ", "stormy ", "windy ",
    "foggy ", "snowy ", "hazy ", "thunderstorm ", "breezy ",
    "king ", "queen ", "prince ", "princess ", "knight ",
    "wizard ", "witch ", "sorcerer ", "warrior ", "archer ",
    "friendship ", "loyalty ", "courage ", "honesty ", "kindness ",
    "wisdom ", "bravery ", "compassion ", "hope ", "love ",
    "barcelona ", "chelsea ", "manchester united ", "liverpool ", "real madrid ",
    "bayern munchen ", "arsenal ", "borussia dortmund ", "ac milan ", "inter milan "
};

char* getRandomWord() {
    int index = rand() % DICTIONARY_SIZE; //Random index
    return dictionary[index];
}

void newPhrase(char **testString) {
  size_t size = 1000 * sizeof(char);
  if(*testString != NULL) {
    free(*testString);
  }
  *testString = (char *)malloc(size);
  if(*testString == NULL) {
    printf("Memory Allocation Failed");
    return;
  }
  memset(*testString, 0, size);
  srand(time(NULL));
  for(int i = 0; i < 10; ++i) {
      strcat(*testString, getRandomWord());
  }
}
