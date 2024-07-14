#include "phrases.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void newPhrase(char **testString) {
  size_t size = 1000 * sizeof(char);
  *testString = (char *)malloc(size);
  if(*testString == NULL) {
    printf("Memory Allocation Failed");
    return;
  }

  strcpy(*testString, "apple banana chair window clock elephant giraffe table ocean river mountain cloud music picture garden computer keyboard mouse screen bottle phone");
}
//
// book lamp camera flower tree grass road car bicycle house door pencil paper notebook jacket shoes socks hat gloves bed pillow blanket chair mirror sink shower toilet kitchen stove 
//fridge oven drawer cabinet plate fork spoon knife cup mug pan glass blender vacuum remote television radio speaker album guitar piano drum trumpet violin candle plant vase curtain carpet 
//shelf wardrobe basket bin brush comb shampoo soap towel jeans shirt sweater scarf ring bracelet necklace earrings perfume makeup mirror rug painting sculpture globe map calendar diary watch umbrella 
//suitcase backpack glasses keys wallet ticket passport sunglasses chair sofa bed frame mattress mattress sheet pillowcase quilt blanket wardrobe chest drawer dresser cupboard cabinet shelf rack hook hanger rod 
//rail stand table desk chair stool lamp light bulb fan heater air conditioner curtain blind shade drape screen shutter curtain blind shade curtain
//hello this is testing