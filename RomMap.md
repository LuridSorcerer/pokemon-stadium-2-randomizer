# ROM Map

Stolen without regard for anyone's rights or feelings from https://datacrystal.romhacking.net/wiki/Pok%C3%A9mon_Stadium_2:ROM_map. 

Some of it is wrong anyway.

## Moves data
Moves data structure is as follow :
* uu vv ww xx yy zz
* uu : Effect id
* vv : Power
* ww : Type id
* xx : Accuracy
* yy : PP
* zz : Probability

0x98430-0x98A12 : Moves data

## Cups Rules

This section is not explained and therefore unhelpful.

* 0xA0084 - Little Cup Rules


## Rental Pokémon

Rental Pokémon structure is as follow :
* uu vv 00 00 ww ww ww ww 00 xx yy yy yy yy yy yy yy yy yy yy zz zz __00 00__
* uu : Level
* vv : Specie id
* ww : Moveset
* xx : Happiness
* yy : Stat exp
* zz : IVs

* 0x1708494 - ~~0x1708C00~~ 0x1708CA4 : Little Cup Rental Pokémon
* 0x1708CB4 - ~~0x170B1D0~~ 0x170A3C4 : Prime Cup / Free Battle Rental Pokémon
* ~~0x170BBA4-0x170D220~~ 0x170BB24 - 0x170D234: Poké Cup / Gym Leader Castle Rental Pokémon

~~Why is this 22 bytes long, but the actual data in the ROM appears to be 24 bytes each?~~

Yeah, it's 24 bytes. And that first 00 appears to be related to held items. More research required.

## Pokémon Base Stats

Pokémon Base Stats structure is as follow :
* rr ss tt uu vv ww xx yy zz
* rr: Pokémon id
* ss: Base HP
* tt : Base Attack
* uu : Base Defense
* vv : Base Speed
* ww : Base Special Attack
* xx : Base Special Defense
* yy : Type id 1
* zz : Type id 2

0x0x98F20 / 0x0x23E90A3 / 0x0x23EBFC0 : Pokémon Base Stats

## Game text

Do I need literally any of this? Probably not.

* 0x1D718B8-0x1D720DF : Pokémon names
* 0x1D724E0-0x1D72C9F : Pokémon species
* 0x1D730A0-0x1D736BF : Pokémon sizes
* 0x1D73AB0-0x1D740C6 : Pokémon weights
* 0x1D744C0-0x1D7A551 : Pokédex descriptions (Gold / Silver)
* 0x1D7A950-0x1D809A7 : Pokédex descriptions (Cristal)
* 0x1D80DA0-0x1D8170C : Moves names
* 0x1D81B00-0x1D86CC2 : Moves descriptions
* 0x1D870BC-0x1D878EB : Items names (Gold / Silver / Cristal)
* 0x1D87CEC-0x1D8910D : Items descriptions (Gold / Silver / Cristal)
* 0x1D89110-0x1D89AB0 : TMs/HMs moves informations (Gold / Silver / Cristal)
* 0x1D89EBC-0x1D8A1E0 : Items names (Red / Blue / Yellow)
* 0x1D8A252-0x1D8A35E : TMs/HMs names (Red / Blue / Yellow)
* 0x1D8A76E-0x1D8B6AD : Items descriptions
* 0x1D8B710-0x1D8C0A3 : TMs/HMs moves informations (Red / Blue / Yellow)
* 0x1D8C100-0x1D8C172 : Types names
* 0x1D8C200-0x1D8C2A7 : Pokémon info
* 0x1D8C2D0-0x1D8C2F8 : Pokémon condition
* 0x1D8C49C-0x1D8CA97 : Team registration
* 0x1D8CDA4-0x1D8DD8E : Battle text
* 0x1D8DDD9-0x1D8DEE1 : Pre-battle (Pokémon selection)
* 0x1D8E0A4-0x1D8E0FD : Johto badges
* 0x1D8E0FF-0x1D8E1E0 : Post-battle
* 0x1D8E1FF-0x1D8E2AB : Between battles
* 0x1D8E2AD-0x1D8E3FC : Gym names
* 0x1D8E3FE-0x1D8E4D1 : Cup names #1
* 0x1D8E528-0x1D8E5B7 : Cup names #2
* 0x1D8E608-0x1D8E8A7 : Achievements text
* 0x1D8E9A8-0x1D8FAC8 : Rules text
* 0x1D8FB50-0x1D8FBBB : Controller 1 not connected
* 0x1D8FBBC-0x1D8FCB7 : Badges and Cups names
* 0x1D8FDFC-0x1D8FEE9 : Gyms and Cups names
* 0x1D8FEEA-0x1D90492 : System messages
* 0x1D9052B-0x1D906AC : Transfer Pack and GB Errors (Save corrupted)
* 0x1D90723-0x1D90A1B : Transfer Pack and GB Errors (Mystery Gift and Mobile Stadium, Unused)
* 0x1D90AA0-0x1D90DFD : Game Options
* 0x1D90F10-0x1D913B9 : Cups Introductions #1, Rules, Settings and Errors
* 0x1D91430-0x1D91991 : In-game descriptions
* 0x1D919E8-0x1D91A34 : Stadium 1 Game Modes (Unused)
* 0x1D91B50-0x1D921BF : Laboratory
* 0x1D92250-0x1D92649 : Pokémon PC #1
* 0x1D926BC-0x1D92893 : Pokémon PC #2
* 0x1D92934-0x1D92E19 : Item PC
* 0x1D92E84-0x1D930EC : Pokémon PC #3
* 0x1D93184-0x1D93474 : Mail PC
* 0x1D934C8-0x1D934F3 : Pokémon PC #4 (Box renaming)
* 0x1D93720-0x1D94332 : Pokémon PC #5 (Pokémon List)
* 0x1D94590-0x1D94C8D : Pokémon Data
* 0x1D94CD8-0x1D94E66 : GB Save Data
* 0x1D94F7C-0x1D95239 : Pokédex menu
* 0x1D9535C-0x1D95550 : Cups Trainer Classes
* 0x1D9570C-0x1D959A4 : Cups Trainer Names
* 0x1D95DB4-0x1D95DC0 : DUMMY1 DUMMY2 (Unseen)
* 0x1D95DC2-0x1D9675F : Pokédex Locations
* 0x1D96878-0x1D96B41 : Cups menu text
* 0x1D96B98-0x1D96BB2 : Demo Text (Unseen)
* 0x1D96C28-0x1D96E15 : Cups Introductions #2
* 0x1D96E68-0x1D96E72 : Trainer COM
* 0x1D96ED8-0x1D96F23 : Rival Introduction
* 0x1D97054-0x1D975DE : Gym Leaders Castle
* 0x1D983C8-0x1D9B9FF : Mini-Games
* 0x1D9BD28-0x1D9BD3B : Number of tries: #03
* 0x1D9BDCC-0x1D9C12D : Pokémon Trade Service
* 0x1D9C614-0x1D9D70E : Credits
* 0x1D9D91C-0x1D9EA45 : Earl's Pokémon Class menus
* 0x1D9EA47-0x1D9F334 : Mobile Stadium data (Unused)
* 0x1D9FCD0-0x1DB44B8 : Earl's Pokémon Class lessons
* 0x1DB4898-0x1DB904B : Earl's Pokémon Class battles
* 0x1DB904D-0x1DB91E8 : Earl's Pokémon Class Trainer names
* 0x1DB91EA-0x1DB9434 : Earl's Pokémon Class battle info #1
* 0x1DB9448-0x1DB98E1 : Earl's Pokémon Class battle info #1
* 0x1DBA5D0-0x1DBFD2F : Earl's Pokémon Class Quiz
* 0x1DC0760-0x1DC18A5 : Pokémon Quiz Mini-Game
* 0x1DC18A7-0x1DC2C24 : Pokémon Quiz Gym Leaders and Towns text
* 0x1DC2C26-0x1DC2E60 : Pokémon Quiz double Types
* 0x1DC2E62-0x1DC2EDE : Pokémon Quiz Shop Prices
* 0x1DC2EE9-0x1DC31AB : Pokémon Quiz miscellaneous text
* 0x1DC31AD-0x1DC352B : Pokémon Quiz Pokémon IDs
* 0x1DC3988-0x1DC5393 : Pokémon Library
* 0x1DC54AC-0x1DC57B0 : Player's Room
* 0x1DC58C0-0x1DC61D3 : Mystery Gift
* 0x1DC6244-0x1DC64EE : GB Tower
* 0x1DC6648-0x1DC6DBA : Mobile Stadium Battle Replay (Unused)
* 0x1DC6E18-0x1DC6FAF : Hall of Fame (Stadium 1, Unused)
* 0x1DC7008-0x1DC7044 : Mystery Gift Dummy text (Unseen)
* 0x1DC71D8-0x1DC7608 : Debug Menu (Unseen)
* 0x1DC76A8-0x1DC799E : Custom Rules
* 0x1DC7AB4-0x1DC7CB1 : CPU Pokémon Nicknames
* 0x1DC7D14-0x1DC7EC5 : Pokémon Move learning and Evolution
* 0x1DC82C8-0x1DC8AF2 : Alternate Color Pokémon Nicknames #1
* 0x1DC8EF8-0x1DC871D : Alternate Color Pokémon Nicknames #2
* 0x1DCA29C-0x1DCA490 : Gym Leaders Castle Trainer Classes
* 0x1DCA7A0-0x1DCAAA3 : Move Relearner
* 0x1DCAAF8-0x1DCAB82 : Debug Messages (Unseen)
* 0x1DCABD8-0x1DCACCB : Debug VS (Unseen)
* 0x1DCAD74-0x1E2DE69 : Trainers speeches