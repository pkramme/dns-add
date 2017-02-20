# dns-add
Adds config files for dnsmasq with costum dns entrees.
Currently it will create only one file, `50-dns-add.conf`.

## Usage
### Add
`dns-add add <name> <address>`

### Remove
`dns-add rm <name>`

## Installation
`make` `sudo make install`  
Uninstall with
`sudo make remove`

## Other features
Currently only this features are available. In the future, there should be
* Add a csv list of addresses
* Select a level other than 50
