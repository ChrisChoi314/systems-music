#include "linkedlist.h"

int main() {
  srand(time(NULL));
  printf("LINKED LIST TESTS\n ====================================\n");
  struct song_node *a = NULL;
  printf("Testing insert_front:\n");
  printf("Inserting celestial elixir by haken: ");
  a = insert_front(a,"celestial elixir","haken" );
  print_list(a);
  printf("Inserting dystopian overture by dream theater: ");
  a = insert_front(a,"dystopian overture","dream theater" );
  print_list(a);
  printf("====================================\n");
  printf("Testing insert_ordered and print_list:\n");
  printf("Adding a whole bunch of songs: ");
  a = insert_ordered(a,"la villa strangiato","rush" );
  a = insert_ordered(a,"cygnus x-1","rush" );
  a = insert_ordered(a,"visions","haken" );
  a = insert_ordered(a,"the remembering","yes" );
  a = insert_ordered(a, "the truth will set you free", "the flower kings");
  a = insert_ordered(a, "stardust we are", "the flower kings");
  a = insert_ordered(a, "garden of dreams", "the flower kings");
  a = insert_ordered(a,"the architect","haken" );
  a = insert_ordered(a, "octavarium", "dream theater");
  print_list(a);
  printf("====================================\n");
  printf("Testing find_node and print_node:\n");
  printf("looking for the remembering by yes\n");
  print_node(find_node(a,"the remembering", "yes"));
  printf("looking for the architect by haken\n");
  print_node(find_node(a,"the architect", "haken"));
  printf("looking for kaleidoscope by transatlantic\n");
  print_node(find_node(a,"kaleidoscope", "transatlantic"));
  printf("====================================\n");
  printf("Testing find_artist:\n");
  printf("looking for rush\n");
  print_list(find_artist(a,"rush"));
  printf("looking for the flower kings\n");
  print_list(find_artist(a,"the flower kings"));
  printf("looking for spock's beard\n");
  print_list(find_artist(a,"spock's beard"));
  printf("====================================\n");
  printf("Testing rand_song:\n");
  print_node(rand_song(a));
  print_node(rand_song(a));
  print_node(rand_song(a));
  printf("====================================\n");
  printf("Testing remove_song:\n");
  printf("Removing visions by haken:\n");
  a = remove_song(a, find_node(a,"visions", "haken"));
  print_list(a);
  printf("Removing garden of dreams by the flower kings:\n");
  a = remove_song(a, find_node(a,"garden of dreams", "the flower kings"));
  print_list(a);
  printf("Removing crystallised by haken (list should not change):\n");
  a = remove_song(a, find_node(a,"visions", "haken"));
  print_list(a);
  printf("====================================\n");
  printf("Testing free_list:\n");
  a = free_list(a);
  printf("List after free_list:");
  print_list(a);

  printf("MUSIC LIBRARY TESTS\n ====================================\n");
  struct song_node * table[27];
  for (int i = 0; i < 27; i++) {
    table[i] = NULL;
  }

  return 0;
}
