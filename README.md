THEBRIDGE
=========
Files and documents regarding THE BRIDGE 2.0

Scherm details
-----------
*resolutie 896x288

Config details
-----------
het lokale path van de config file is: 'd:\thebridge\config.json'.
Maak een verwijzing hiernaar in je eigen applicatie specifieke config-file  .
**locations** is een lijst met servers, deze lijst is op elke locatie hetzelfde.
**local_idx** en **remote_idx** geven welke locatie de lokale is. Bijv. de color feed aan "eigen" kant is op te vragen met `config["locations"][ config["local_idx"] ]["server"] + "/color" ` . Deze indices zijn dus omgewisseld op beide locaties.

Bij precies één van de servers staat **is_master** op `true`. 
De **specs** bevat informatie over de camera en setup. 
**screen** bevat informatie over de setup van het scherm. De x-y positie waar je applicatie gepositioneerd moet worden na het opstarten en de resolutie van het led-scherm.

```json
    {
      "locations" : 
      [
        {"name": "Den Haag", "server": "192.168.1.61:1338", "game": "localhost"},
        {"name": "Stockholm", "server": "213.127.157.20:1338", "game": "213.127.157.20"}
      ],
      
      "local_idx": 1,
      "remote_idx": 0,

      "is_master": true, 
      
      "specs": {
        "color_res": {"width": 1024, "height": 330},
        "depth_res": {"width": 160, "height": 120},
        "depth_mapping": {"x": 200, "y": -10, "width": 624, "height": 350 }
      }, 

      "screen": {
        "pos" : {"x": 30, "y": 30},
        "res" : {"width": 896, "height": 288}
      }
    }