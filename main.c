#include "linkedlist.h"
#include "musiclib.h"

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
  a = remove_song(a, find_node(a,"crystallised", "haken"));
  print_list(a);
  printf("====================================\n");
  printf("Testing free_list:\n");
  a = free_list(a);
  printf("List after free_list:");
  print_list(a);

  printf("====================================\n");
  printf("MUSIC LIBRARY TESTS\n ====================================\n");
  struct song_node * table[27];
  for (int i = 0; i < 27; i++) {
    table[i] = NULL;
  }
  printf("Testing add_song and print_lib:\n");
  printf("Adding a whole bunch of songs:\n");
  add_song(table,"celestial elixir","haken" );
  add_song(table,"dystopian overture","dream theater" );
  add_song(table,"la villa strangiato","rush" );
  add_song(table,"cygnus x-1","rush" );
  add_song(table,"no surprises","radiohead" );
  add_song(table,"visions","haken" );
  add_song(table,"the remembering","yes" );
  add_song(table, "the truth will set you free", "the flower kings");
  add_song(table, "stardust we are", "the flower kings");
  add_song(table, "garden of dreams", "the flower kings");
  add_song(table,"the architect","haken" );
  add_song(table, "octavarium", "dream theater");
  add_song(table, "renai circulation", "*namirin");
  print_lib(table);

  printf("====================================\n");
  printf("Testing print_letter:\n");
  print_letter(table, 'r');

  printf("====================================\n");
  printf("Testing print_artist:\n");
  print_artist(table, "rush");

  printf("====================================\n");
  printf("Testing search_song:\n");
  printf("looking for the remembering by yes\n");
  print_node(search_song(table,"the remembering", "yes"));
  printf("looking for the architect by haken\n");
  print_node(search_song(table,"the architect", "haken"));
  printf("looking for kaleidoscope by transatlantic\n");
  print_node(search_song(table,"kaleidoscope", "transatlantic"));
  printf("====================================\n");
  printf("Testing search_artist:\n");
  printf("looking for rush\n");
  print_list(search_artist(table,"rush"));
  printf("looking for the flower kings\n");
  print_list(search_artist(table,"the flower kings"));
  printf("looking for spock's beard\n");
  print_list(search_artist(table,"spock's beard"));
  printf("====================================\n");
  printf("Testing shuffle:\n");
  shuffle(table, 5);
  printf("====================================\n");
  printf("Testing delete_song:\n");
  printf("Deleting visions by haken:\n");
  delete_song(table, search_song(table,"visions", "haken"));
  print_lib(table);
  printf("Removing garden of dreams by the flower kings:\n");
  delete_song(table, search_song(table,"garden of dreams", "the flower kings"));
  print_lib(table);
  printf("Removing renai circulation by *namirin:\n");
  delete_song(table, search_song(table,"renai circulation", "*namirin"));
  print_lib(table);
  printf("====================================\n");
  printf("Testing clear_lib:\n");
  clear_lib(table);
  printf("List after clear_lib:");
  print_lib(table);
  return 0;
}
