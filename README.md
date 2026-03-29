# 🏠 Calcolo IMU 2023

Programma per il calcolo dell'Imposta Municipale Unica (IMU) sviluppato in C come progetto scolastico terza superiore (2024).

> Supporta i comuni di Legnago, Cerea, Andrano, Lecce e Isola della Scala con le relative aliquote aggiornate.

---

## ✨ Funzionalità

- Calcolo IMU per **fabbricati**, **aree fabbricabili** e **terreni**
- Supporto per più immobili contemporaneamente
- Gestione **abitazione principale** con esonero automatico
- Categorie catastali **gruppo A** (A/1 → A/11) e **gruppo C** (C/1 → C/7)
- Calcolo automatico dei **mesi di possesso** in base alla data di acquisto
- Agevolazioni:
  - Fabbricato **inagibile o inabitabile** (-50% base imponibile)
  - **Comodato d'uso** con contratto registrato (-50%)
  - **Canone concordato** (-75%)
  - **Esonero pertinenza** con rendita catastale più alta
- **Detrazione** di 200€ per abitazione principale nei casi previsti
- Interfaccia console colorata con **bandiera italiana** nell'header
- Ordinamento IMU con **Quick Sort**

---

## 🏙️ Comuni supportati

| Codice | Comune |
|---|---|
| E512 | Legnago |
| C498 | Cerea |
| A281 | Andrano |
| E506 | Lecce |
| E349 | Isola della Scala |

---

## 🛠️ Tecnologie

- Linguaggio **C** (standard C99)
- Compilatore **GCC / MinGW**
- API Windows Console per la gestione dei colori (`windows.h`)
- Header custom: `RenditaCatastale&Aliquote.h`, `quick_sort.h`

---

## ▶️ Compilazione ed esecuzione

```bash
gcc main.c -o imu -lm
./imu
```

> ⚠️ Il programma usa `windows.h` per la grafica console — funziona solo su Windows.

---

## 📁 Struttura

```
imu/
├── main.c                      # Programma principale
├── RenditaCatastale&Aliquote.h # Funzioni base imponibile e aliquote per comune
├── quick_sort.h                # Algoritmo Quick Sort
└── main.exe                    # Eseguibile precompilato
```

---

## 📌 Note

Progetto scolastico realizzato nel 2024. Le aliquote inserite sono quelle vigenti al momento dello sviluppo e potrebbero non essere aggiornate.
