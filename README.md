# PRK - vlastní jazyk

1. OPERACE - vlastní operace ~ -> daný dvě čísla vynásobí a přičte k výsledku hodnoty obou čísel -> a~b = a*b + a + b
- celkově tedy operace +, * a ~
- pririty jsou řešeny následovně:
	- nejvyšší prioritu má vlastní operace ~
	- druhou nejvyšší prioritu má násobení *
	- nejnižší prioritu má sčítání +


2. DATOVÉ TYPY - (integer), hexadecimální čísla (0x...), binární čísla (b10010) a array (v hranatých závorkách, čísla oddělené čárkou)
- sčítání, násobení a ~ -> výsledkem bude vždy datový typ prvního čísla -> tzn. OxA + 21 = 0x1F
- sčítání, násobení a ~ čísel a polí - vždy např. sečtu číslo s každým prvkem pole, výsledkem bude datový typ čísla z pole - tzn. datový typ čísel v poli se nezmění - příklad: [0xF1,0xD4,0xCC] ~ 2 = [0x2D5, 0x27E, 0x266]
- array nesmí být prázdné -> [] není platné

3. NĚCO UNIKÁTNÍHO - Random číslo - do výpočtu můžu zadat funkci rand() s tím, že může mít argumenty:

- rand() - bez argumentů je to int od 0 do 100
- rand(type) - určím datový typ (string) -> hodnoty "int", "bin", "hex"
- rand(x,y) - horní a dolní hranice random čísla (x a y jsou int), výsledné číslo bude int
- rand(x,y,type) - horní a dolní hranice s určeným datovým typem
- rand(n) - výsledkem bude random pole intů o délce n hodnot, hodnoty 0-100
- rand(n,type) - pole, n hodnot, určený datový typ
- rand(x,y,n) - výsledkem bude random pole intů o délce n hodnot, x a y jsou horní a dolní hranice
- rand(x,y,n,type) - pole čísel se specifikovaným datovým typem, n hodnot, určená horní a dolní hranice
