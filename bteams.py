inFile=open('bteams.in','r')
out=open('bteams.out','w')

## this problem is not done.
## This is a permutation problem. After optimization, it becomes combination
## problem

player_skill=[0]*12
player_team=[0]*12
team_count=[0]*4
answer = -1

for i in range(12):
    player_skill[i]=int(inFile.readline())

def recurse(player):
    global answer
    ## if we have assigned all players, start calculating the difference
    
    if player==12:
        team_skill=[0,0,0,0]
        for i in range(12):
            team_skill[player_team[i]] += player_skill[i]

            top=max(team_skill)
            bot=min(team_skill)

            if answer == -1 or (top - bot) < answer:
                answer = top - bot
                print(answer)
                return

    ## permutate, dept first search
    ## how about combination?
    for team in range(4):
        if team_count[team]<3:   ## save the level of the tree, 4*3 = 12 players
            player_team[player]=team   ##assign player to a team
            team_count[team] += 1    
            recurse(player+1)
            team_count[team] -= 1   ##back out of recusion and go to another branch


recurse(0)
out.write(str(answer))
inFile.close()
out.close()
