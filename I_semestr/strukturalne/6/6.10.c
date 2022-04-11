#include <stdio.h>
#include <stdlib.h>

enum Type { Single = 1, Double };
enum Floor { First = 1, Second };

struct Room {
    unsigned number;
    enum Type type;
    enum Floor floor;
};

void printRooms(struct Room* rooms, unsigned count);

int main() {
    unsigned n;

    printf("Podaj n: \n");
    scanf("%u", &n);

    struct Room* rooms = (struct Room*)malloc(n * sizeof(struct Room));

    unsigned i = 0;
    unsigned nr_of_rooms = n;
    unsigned room_nr = 0;

    while(nr_of_rooms) {
        if (i + 1 == 13) {
            i++;
            continue;
        }

        if ((i + 1) % 2 == 0) {
            rooms[room_nr].floor = First;
            rooms[room_nr].type = Double;
        } else {
            rooms[room_nr].floor = Second;
            rooms[room_nr].type = Single;
        }
        rooms[room_nr].number = i + 1;
        i++;
        nr_of_rooms--;
        room_nr++;

        printf("%u\n", i);
    }

    printRooms(rooms, n);

    return 0;
}

void printRooms(struct Room* rooms, unsigned count) {
    unsigned i;

    printf("Nr pokoju\tIle osob\tPietro\n");
    for (i = 0; i < count; i++) {
        printf("%u\t\t%i\t\t%i\n", rooms[i].number, rooms[i].type, rooms[i].floor);
    }
}
