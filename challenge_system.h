#ifndef CHALLENGE_SYSTEM_H_
#define CHALLENGE_SYSTEM_H_

#include "visitor_room.h"
#include "system_additional_types.h"

typedef struct SChallengeRoomSystem
{

//#include "challenge_room_system_fields.h"

    char *system_name;
    int system_last_known_time;
    Challenge *system_challenges;
    int system_num_challenges;
    ChallengeRoom *system_rooms;
    int system_num_rooms;
    VisitorsList visitors_list_head;

} ChallengeRoomSystem;


Result create_system(char *init_file, ChallengeRoomSystem **sys);


Result destroy_system(ChallengeRoomSystem *sys, int destroy_time,
                      char **most_popular_challenge_p, char **challenge_best_time);


Result visitor_arrive(ChallengeRoomSystem *sys, char *room_name, char *visitor_name, int visitor_id, Level level, int start_time);


Result visitor_quit(ChallengeRoomSystem *sys, int visitor_id, int quit_time);


Result all_visitors_quit(ChallengeRoomSystem *sys, int quit_time);


Result system_room_of_visitor(ChallengeRoomSystem *sys, char *visitor_name, char **room_name);


Result change_challenge_name(ChallengeRoomSystem *sys, int challenge_id, char *new_name);


Result change_system_room_name(ChallengeRoomSystem *sys, char *current_name, char *new_name);


Result best_time_of_system_challenge(ChallengeRoomSystem *sys, char *challenge_name, int *time);


Result most_popular_challenge(ChallengeRoomSystem *sys, char **challenge_name);


#endif // CHALLENGE_SYSTEM_H_

