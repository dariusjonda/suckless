Continued development of this dmenu script: 

<https://github.com/jukil/dmenu-scripts-collection/blob/master/dmenu-recent-aliases>

Added support for:

- Aliases specified by the user's bash configuration
- Support for arguments and launching commands in xterm
    - `;` suffix. Open in xterm. e.g. `vim;`
    - `;;` suffix. Open in xterm and olds xterm open after the command has run. e.g. `ls /etc;;`
- Recent args suggestion:
    - `*` suffix. Open dmenu with suggestions of recent arguments. e.g. `killall*` suggests `killall compton, killall xterm, killall python`
