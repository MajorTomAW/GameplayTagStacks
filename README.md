# Gameplay Tag Stacks Plugin

Replicated Gameplay Tags that can be used in a stack-like manner.  
Similar to what [Lyra Starter Game](https://dev.epicgames.com/community/learning/paths/Z4/lyra-starter-game) uses.

Usefull for storing stats (Kills / Assists / Deaths / Ammo / etc. ) that need to be replicated to other clients.


# Example **Lyra Starter Game**

The [Lyra Starter Game](https://dev.epicgames.com/community/learning/paths/Z4/lyra-starter-game) uses Gameplay Tag Stacks for multiple purposes.  
As an example the ``W_MatchScoreBoard_Elimination`` uses them to access the player stats (Eliminations/Deaths/Assists) and to display them.

![image](https://github.com/user-attachments/assets/c17c40a5-4ea0-4329-a13c-4dbe64c87716)


Each player state contains 3 Gameplay Tag Stacks:
- Tag: ``ShooterGame.Score.Elimination``    Stack Count: <_the amount of eliminations_>
- Tag: ``ShooterGame.Score.Deaths``         Stack Count: <_the amount of deaths_>
- Tag: ``ShooterGame.Score.Assists``        Stack Count: <_the amount of assists_>
