# Kamara-Didaktikoa

![1676547753684 (1)](https://user-images.githubusercontent.com/123642231/219358579-3597a257-894b-42f9-99d8-ac4e3c323b59.jpg)


ESKEMA OROKORRA

![Kam Did  Eskema Orokorra](https://user-images.githubusercontent.com/123642231/218746013-7755d9c1-1772-4d88-9fa1-78054ea7c9c3.jpg)


RGB FOTODIODOAK

![Captura de pantalla 2023-02-16 125057](https://user-images.githubusercontent.com/123642231/219357601-f72d3c54-8ade-4725-abcb-7115994811ee.png)

Transdukzioa : argi/fotoi kopurua → energia elektrikoan  bilakatzea
Fotodiodoak , jasotako argi kopuruarekiko bere erresistentzia balioak aldagarria
Fotoiak +++           Erresitentzia +++  




TENTSIO ZATITZAILEA

![Captura de pantalla 2023-02-16 125500](https://user-images.githubusercontent.com/123642231/219358451-d6a80b4f-95b9-4b6c-9f59-ef619cb39aef.png)

Tentsio Zatitzailea osatu beharra izan dugu diodo eta erresistentziekin 
1,9V - 3,3V tartean doitzeko irteerako tentsioa 
2 Mohm ekoa hautatu dugu
Fotodiodoaren balioa R ++ → Irteerako V --  




IRAKURKETA ANALOGIKOA

![Captura de pantalla 2023-02-16 124756](https://user-images.githubusercontent.com/123642231/219357138-f9db6c1f-6b00-42b7-8dbd-8ddfa8083848.png)

Sarrera analogikoak tentsioa irakurtzeko erabiliak
Teensy 4.0 rako 3,3V ko muga sarrera analogikoetan
0V eta 3,3Veko tentsiok irakurriko ditugu 14-…-23 pinetan
Irakurketak 0 eta 1023 balioen artean transduzituko dira




ZENER IMPLEMENTAZIOA   

![Captura de pantalla 2023-02-16 125249](https://user-images.githubusercontent.com/123642231/219358002-af632ce6-f0d6-4e23-950e-0fdfb508f1ea.png)

Tentsio Zatitzailearen irteerako V mugatu eta kontrolatzeko :
Zener diodo bat hautatu dugu
Sarrera analogikoetan , 3,3V eduki dezagun



KORRONTE DESBIDERATZEA


Arduinoaren sarrera analogikoak erresistentzia bat
dute eta orduan corrontea desbiratzen da.
Horren ondorioz erresistentzia totala jaisten da




IMPEDENTZIA AKOPLATZAILEA

![Captura de pantalla 2023-02-16 123525](https://user-images.githubusercontent.com/123642231/219354371-7d6e1985-1456-44be-9a48-ba7ecf306e97.png)

Iturri gisa inpedantzia doitzen duen zirkuitu bat 
eraman behar du. Kasu horretan, anplifikadore
operazional bat erabiliko dugu jarraitzaile gisa, 
berrelikadurarekin eta irabazi unitarioarekin.




KONTROL ETAPA

![Proyecto nuevo](https://user-images.githubusercontent.com/123642231/219346934-aaf1b304-5f69-492b-8dd6-f27b6484ab66.jpg)

Analog Devices markako Multipexoreak hautatu ditugu : ADG732
Teensy 4.0 a hautatua ,600MHz prozesamendu duelako
SPI Transmisorea hautatu dugu : NRF24L01
Proteus 8 Profesional programa  , PCBa diseinatzeko
Irakurketa analogikoan burutzen dute Multiplexoreek
4 multiplexore bitartez lagindu eta kontrolatuko ditugu eskuratutako tentsio baloreak , jarraian haiek Teensyra bideratuz.
Kolore bakoitzeko multiplexore bat : 1REDmultiplexor , 2GREENmultiplexor , 3BLUEmultiplexor . 
Eta beste azken bat ADRESS funtzioa beteko lukeena 4COMmultiplexor .
4COMmultiplexor :  D0…D9 pinek , seinaleari direkzionalidadea emanez 



SPI KOMUNIKAZIOA
![Captura de pantalla 2023-02-16 122921](https://user-images.githubusercontent.com/123642231/219353265-3b7b1993-2d48-4509-b1df-82817aa2cca4.png)

Airezko komunikazio sistema hautatu dugu
Hortarako NRF24L01 komunikazio modulua hautatu dugu
1000m ko irismena zihurtatua
2,4GHz ko banda maiztasuna erabitzen dute 
Programa erabiltzeko
BOM low cost 



