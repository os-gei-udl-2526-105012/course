# tic-tac-toe.sh

#!/usr/bin/bash

# Constants
declare -r VERMELL="\033[31m"
declare -r VERD="\033[32m"
declare -r BLAU="\033[34m"
declare -r NC="\033[0m"
declare -r N=3

# Variables per controlar el joc
torn_actual=1 # Torn actual
jugant=true # Booleà per controlar si es continua jugant

# Funcions per mostrar les jugades amb colors diferents
jugador1=${VERD}"X"${NC}
jugador2=${BLAU}"O"${NC}

# Inicialitzar el taulell de joc com un array de 9 elements representant les caselles
taulell=( 1 2 3 4 5 6 7 8 9 )

# Imprimir el taulell de joc
imprimir_taulell() {
    # Esborrar la pantalla
    clear
    for (( casella = 1; casella <= 9; casella++ )); do
        echo -n "| ${taulell[$(($casella - 1))]} "
        if (( casella % N == 0 )); then
            echo "|"
        fi
    done
}

# Comprova si la casella es valida
# Una casella és vàlida si està dins dels límits del taulell i no està ocupada

casella_valida() {
    if (( casella < 1 || casella > 9 )); then
        return 1
    fi

    if [[ ${taulell[$(($casella - 1))]} == "X" || ${taulell[$(($casella - 1))]} == "O" ]]; then
        return 1
    fi

    return 0
}

# Comprovar si hi ha un guanyador
guanyador() {

    # Comprovar files
    for (( i = 0; i < $N; i++ )); do
        if [[ ${taulell[$(($i * $N))]} == $jugada && ${taulell[$(($i * $N + 1))]} == $jugada && ${taulell[$(($i * $N + 2))]} == $jugada ]]; then
            return 0
        fi
    done

    # Comprovar columnes
    for (( i = 0; i < $N; i++ )); do
        if [[ ${taulell[$i]} == $jugada && ${taulell[$(($i + $N))]} == $jugada && ${taulell[$(($i + 2 * $N))]} == $jugada ]]; then
            return 0
        fi
    done

    # Comprovar diagonal principal
    if [[ ${taulell[0]} == $jugada && ${taulell[4]} == $jugada && ${taulell[8]} == $jugada ]]; then
        return 0
    fi

    # Comprovar diagonal secundària
    if [[ ${taulell[2]} == $jugada && ${taulell[4]} == $jugada && ${taulell[6]} == $jugada ]]; then
        return 0
    fi

    return 1

}


# Implementació d'un torn
torn(){

    if (( torn_actual % 2 == 0 )); then
        jugada="X"
    else
        jugada="O"
    fi


    echo -n "Introdueix la casella on vols fer la jugada: "
    read casella

    while ! casella_valida; do
        echo -n "Casella no vàlida. Torna a introduir la casella: "
        read casella
    done

    taulell[$(($casella - 1))]=$jugada

    if guanyador; then
        if (( torn_actual % 2 == 0 )); then
            echo "Ha guanyat el Jugador 2"
        else
            echo "Ha guanyat el Jugador 1"
        fi
        jugant=false
        return
    fi

    torn_actual=$(($torn_actual + 1))

    if (( torn_actual == 9 )); then
        echo "Empat"
        jugant=false
        return
    fi

}


while $jugant; do
    imprimir_taulell
    torn
done
