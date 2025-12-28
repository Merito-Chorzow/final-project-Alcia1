# Dokumentacja Testów - Sterownik Oświetlenia

## Test INIT
1. Kroki:
- Włączenie symulacji
2. Efekt oczekiwany:
Zmiana jasności diody do 20%, a następnie wygaśnięcie diody. W terminalu widaomość o zainicjowaniu stanu INIT oraz zmianie go do IDLE. 
3. Efekt otrzymany:
```
FSM: System zainicjalizowany w stanie INIT
--- SYSTEM READY ---
I (453) main_task: Returned from app_main()
LOGIC: Jasność LED: 10% (Cel: 20%)
LOGIC: Jasność LED: 20% (Cel: 20%)
FSM: Test inicjalizacyjny zakończony. Zmiana na STATE_IDLE
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
```

## Zmiana jasności przyciskiem
1. Kroki:
- Kliknięcie przycisku
- Odczekanie ok. 4 sekund
- Kliknięcie przycisku
2. Efekt oczekiwany:
Łagodna zmiana jasności diody od zera do maksymalnej jasności, a po kolejnym kliknięciu łagodne wygaszenie diody do zera.
3. Efekt otrzymany:
```
DEBUG: Przycisk wciśnięty!
FSM: [EVENT] Przycisk naciśnięty. Start rozjaśniania
LOGIC: Jasność LED: 10% (Cel: 100%)
LOGIC: Jasność LED: 20% (Cel: 100%)
LOGIC: Jasność LED: 30% (Cel: 100%)
LOGIC: Jasność LED: 40% (Cel: 100%)
LOGIC: Jasność LED: 50% (Cel: 100%)
LOGIC: Jasność LED: 60% (Cel: 100%)
LOGIC: Jasność LED: 70% (Cel: 100%)
LOGIC: Jasność LED: 80% (Cel: 100%)
LOGIC: Jasność LED: 90% (Cel: 100%)
LOGIC: Jasność LED: 100% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
FSM: [EVENT] Przycisk naciśnięty. Start gaszenia
LOGIC: Jasność LED: 90% (Cel: 0%)
LOGIC: Jasność LED: 80% (Cel: 0%)
LOGIC: Jasność LED: 70% (Cel: 0%)
LOGIC: Jasność LED: 60% (Cel: 0%)
LOGIC: Jasność LED: 50% (Cel: 0%)
LOGIC: Jasność LED: 40% (Cel: 0%)
LOGIC: Jasność LED: 30% (Cel: 0%)
LOGIC: Jasność LED: 20% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
```

## Zmiana scen - DAY
1. Kroki:
- Wpisanie w konsolę SCENE:DAY
2. Efekt oczekiwany:
Zmiana jasności diody do 100%.
3. Efekt otrzymany:
```
SCENE:DAYLOGIC: Uruchomiono scene DAY (100%)
LOGIC: Jasność LED: 10% (Cel: 100%)
LOGIC: Jasność LED: 20% (Cel: 100%)
LOGIC: Jasność LED: 30% (Cel: 100%)
LOGIC: Jasność LED: 40% (Cel: 100%)
LOGIC: Jasność LED: 50% (Cel: 100%)
LOGIC: Jasność LED: 60% (Cel: 100%)
LOGIC: Jasność LED: 70% (Cel: 100%)
LOGIC: Jasność LED: 80% (Cel: 100%)
LOGIC: Jasność LED: 90% (Cel: 100%)
LOGIC: Jasność LED: 100% (Cel: 100%)
```

## Zmiana scen - SUNSET
1. Kroki:
- Wpisanie w konsolę SCENE:SUNSET
2. Efekt oczekiwany:
Zmiana jasności diody do 50%.
3. Efekt otrzymany:
```
SCENE:SUNSETLOGIC: Uruchomiono scene SUNSET (50%)
LOGIC: Jasność LED: 10% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 50%)
LOGIC: Jasność LED: 30% (Cel: 50%)
LOGIC: Jasność LED: 40% (Cel: 50%)
LOGIC: Jasność LED: 50% (Cel: 50%)
```

## Zmiana scen - NIGHT
1. Kroki:
- Wpisanie w konsolę SCENE:NIGHT
2. Efekt oczekiwany:
Zmiana jasności diody do 0%.
3. Efekt otrzymany:
```
SCENE:NIGHTLOGIC: Uruchomiono scene NIGHT (0%)
LOGIC: Jasność LED: 90% (Cel: 0%)
LOGIC: Jasność LED: 80% (Cel: 0%)
LOGIC: Jasność LED: 70% (Cel: 0%)
LOGIC: Jasność LED: 60% (Cel: 0%)
LOGIC: Jasność LED: 50% (Cel: 0%)
LOGIC: Jasność LED: 40% (Cel: 0%)
LOGIC: Jasność LED: 30% (Cel: 0%)
LOGIC: Jasność LED: 20% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
```

## Stan Fault
1. Kroki:
- Przytrzymanie przycisku przez ok. 3 sekundy
- Pojedyncze wciśnięcie przycisku
2. Efekt oczekiwany:
Miganie diody jako oznaka wejścia w stan Fault. Następnie wyłączenie się diody i powrót do stanu IDLE.
3. Efekt otrzymany:
```
FSM: [EVENT] Przycisk naciśnięty. Start rozjaśniania
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 10% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 20% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 30% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 40% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 50% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 60% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 70% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 80% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 90% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 100% (Cel: 100%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
FSM: [ERROR] Przycisk zablokowany zbyt długo! Zmiana na STATE_FAULT
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 90% (Cel: 0%)
DEBUG: Przycisk wciśnięty!
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 80% (Cel: 0%)
DEBUG: Przycisk wciśnięty!
LOGIC: Jasność LED: 70% (Cel: 0%)
LOGIC: Jasność LED: 60% (Cel: 0%)
LOGIC: Jasność LED: 50% (Cel: 0%)
LOGIC: Jasność LED: 40% (Cel: 0%)
LOGIC: Jasność LED: 30% (Cel: 0%)
LOGIC: Jasność LED: 20% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 0%)
DEBUG: Przycisk wciśnięty!
FSM: Resetowanie błędu -> STATE_IDLE
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
```

## Komendy UART - ON i OFF
1. Kroki:
- Wpisanie w konsolę komendy ON
- Wpisanie w konsolę komeny OFF
2. Efekt oczekiwany:
Rozjaśnienie się diody do maksymalnego poziomu. Następnie zmiana jasności aż do zera.
3. Efekt otrzymany:
```
ON
UART: Aktywowano rozjasnianie (100%)
LOGIC: Jasność LED: 10% (Cel: 100%)
LOGIC: Jasność LED: 20% (Cel: 100%)
LOGIC: Jasność LED: 30% (Cel: 100%)
LOGIC: Jasność LED: 40% (Cel: 100%)
LOGIC: Jasność LED: 50% (Cel: 100%)
LOGIC: Jasność LED: 60% (Cel: 100%)
LOGIC: Jasność LED: 70% (Cel: 100%)
LOGIC: Jasność LED: 80% (Cel: 100%)
LOGIC: Jasność LED: 90% (Cel: 100%)
LOGIC: Jasność LED: 100% (Cel: 100%)
OFF
UART: Aktywowano gaszenie (0%)
LOGIC: Jasność LED: 90% (Cel: 0%)
LOGIC: Jasność LED: 80% (Cel: 0%)
LOGIC: Jasność LED: 70% (Cel: 0%)
LOGIC: Jasność LED: 60% (Cel: 0%)
LOGIC: Jasność LED: 50% (Cel: 0%)
LOGIC: Jasność LED: 40% (Cel: 0%)
LOGIC: Jasność LED: 30% (Cel: 0%)
LOGIC: Jasność LED: 20% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
```

## Komendy UART - SET
1. Kroki:
- Wpisanie w konsolę komendy SET:50
- Wpisanie w konsolę komendy SET:100
- Wpisanie w konsolę komendy SET:0
- Wpisanie w konsolę komendy SET:10
2. Efekt oczekiwany:
Rozjaśnienie się diody do 50%. Następnie rozjaśnienie do maksymalnego poziomu. Nastepnie wyłącznenie się diody. Następnie włączenie się diody z bardzo małą jasnością.
3. Efekt otrzymany:
```
SET:50
UART: Ustawiono cel na 50%
LOGIC: Jasność LED: 10% (Cel: 50%)
LOGIC: Jasność LED: 20% (Cel: 50%)
LOGIC: Jasność LED: 30% (Cel: 50%)
LOGIC: Jasność LED: 40% (Cel: 50%)
LOGIC: Jasność LED: 50% (Cel: 50%)
SET:100
UART: Ustawiono cel na 100%
LOGIC: Jasność LED: 60% (Cel: 100%)
LOGIC: Jasność LED: 70% (Cel: 100%)
LOGIC: Jasność LED: 80% (Cel: 100%)
LOGIC: Jasność LED: 90% (Cel: 100%)
LOGIC: Jasność LED: 100% (Cel: 100%)
SET:0
UART: Ustawiono cel na 0%
LOGIC: Jasność LED: 90% (Cel: 0%)
LOGIC: Jasność LED: 80% (Cel: 0%)
LOGIC: Jasność LED: 70% (Cel: 0%)
LOGIC: Jasność LED: 60% (Cel: 0%)
LOGIC: Jasność LED: 50% (Cel: 0%)
LOGIC: Jasność LED: 40% (Cel: 0%)
LOGIC: Jasność LED: 30% (Cel: 0%)
LOGIC: Jasność LED: 20% (Cel: 0%)
LOGIC: Jasność LED: 10% (Cel: 0%)
LOGIC: Jasność LED: 0% (Cel: 0%)
SET:10
UART: Ustawiono cel na 10%
LOGIC: Jasność LED: 10% (Cel: 10%)
```

## Komendy UART - STATS
1. Kroki:
- Wpisanie w konsolę komendy STATS
2. Efekt oczekiwany:
Wypisanie w konsoli informacji o aktualnym stanie, uptime, liczbie wpisanych komend, błędów uart, latency, oraz o aktualnej jasności diody.
3. Efekt otrzymany:
```
STATS
--- TELEMETRY ---
Stan: [ IDLE ]
Uptime:      33 cykli (3. 3 s)
Komendy:     1 odebranych
Bledy UART:  0 (Overflow/Unknown)
Latency:     700 ms (Ostatnie narastanie)
Jasnosc:     0%
-------------------
```

## Komendy UART - błędna komenda
1. Kroki:
- Wpisanie w konsolę nieznanej komendy (w tym przypadku NIEZNANE)
- Wpisanie w konsolę zbyt długiej komendy (więcej niż 128 znaków)
- wpisanie komendy STATS
2. Efekt oczekiwany:
Wyświetlenie komunikatu o nieznanej komendzie. Następnie ponowne wyświetlenie komunikatu o nieznanej komendzie. Następnie wyświetlenie telemetrii ze zliczonymi 2 błędami UART.
3. Efekt otrzymany:
```
NIEZNANE
UART ERROR: Nieznana komenda [NIEZNANE]. Dostepne: ON, OFF, SET:val, STATS, SCENE:DAY/SUNSET/NIGHT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
UART ERROR: Nieznana komenda [aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa]. Dostepne: ON, OFF, SET:val, STATS, SCENE:DAY/SUNSET/NIGHT
STATS
--- TELEMETRY ---
Stan: [ IDLE ]
Uptime:      494 cykli (49. 4 s)
Komendy:     3 odebranych
Bledy UART:  2 (Overflow/Unknown)
Latency:     700 ms (Ostatnie narastanie)
Jasnosc:     0%
-------------------
```

Wszystkie testy zwróciły oczekiwany wynik.