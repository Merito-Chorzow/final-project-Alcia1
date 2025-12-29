# Sterownik Oświetlenia LED (ESP32) v1.0.0

**Temat: terownik oświetlenia (PWM + sceny)** 

**Autor: Alicja Grochowina**

**Nr Albumu: 180746**

## Opis Projektu

Projekt realizuje sterownik oświetlenia oparty na systemie FreeRTOS i mikrokontrolerze ESP32. Urządzenie pozwala na płynne sterowanie jasnością diody LED za pomocą przycisku fizycznego oraz komend terminalowych (UART).

Kluczowe funkcjonalności:

- Maszyna Stanów: Pełny cykl życia urządzenia: INIT -> IDLE -> RUN -> FAULT -> IDLE.
- Slew-rate: Eliminacja gwałtownych skoków jasności (zmiana o 5% co 100ms).
- Sceny świetlne: Predefiniowane tryby SUNSET, NIGHT oraz DAY.
- System Telemetrii: Monitorowanie czasu pracy, błędów oraz opóźnień.
- Tryb Fault: Automatyczne wykrywanie zablokowania przycisku i przejście w tryb bezpieczny.

## Instrukcja Obsługi

Po połączeniu się z terminalem, system akceptuje następujące komendy:
- ON / OFF - Szybkie włączanie/wyłączanie (z zachowaniem płynności).
- SET:X - Ustawienie jasności na konkretny poziom (np. SET:50).
- SCENE:SUNSET - Przejście do trybu wieczornego (50% jasności).
- SCENE:NIGHT - Całkowite wygaszenie (0% jasności).
- SCENE:DAY - Całkowite rozjaśnienie (100% jasności).
- STATS - Wyświetlenie raportu telemetrii i aktualnego stanu maszyny.

## Architektura

System został zaprojektowany w sposób deterministyczny. Scheduler pracuje z interwałem 100ms, co zapewnia przewidywalność algorytmów sterujących i stałe obciążenie procesora. Więcej można przeczytać w pliku design.md

## Jak uruchomić

- Pobierz repo.
- Zainstaluj Wokwi Simulator w VS Code.
- W rozszerzeniu kliknij "request a new wokwi license" i przejdź przez proces zdobywania licencji.
- Kliknij w plik diagram.json.
- Kliknij przycisk Start the simulation.
