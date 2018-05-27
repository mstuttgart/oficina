#!/bin/bash
# Create sequential issue in milestone to your repositories

#### Contants and variables

VERSION="0.1.0"

USERNAME=''
PASSWORD=''
REPO=''
URL=''
TITLE=''
LABELS=''
MILESTONE=0
QUANT=0
STEP_BEGIN=0

#### Functions

function usage {
    echo "Create sequential issues in milestone in Github"
    echo ""
    echo "--help, -h      Show this help"
    echo "--version, -v   Show this script version"
    echo "--user, -u      Github username"
    echo "--password, -p  Github password"
    echo ""
    echo "Usage:
                $(basename "$0") -u username -p password owner/repo"
    echo ""

}

function version {
    echo "$VERSION"
    echo ""
}

while test -n "$1"
do
    case "$1" in

        -h | --help)
            usage
            exit 0
        ;;

        -v | --version)
            version
            exit 0
        ;;

        -u | --username)
            shift
            USERNAME="$1"

            if test -z "$USERNAME"
            then
                echo "-u or --username argument not found"
                exit 1
            fi
        ;;
        
        -p | --password)
            shift
            PASSWORD="$1"

            if test -z "$PASSWORD"
            then 
                echo "-p or --password argumento not found"
                exit 1
            fi
        ;;

        *)
            REPO=$1

            if test -z "$REPO"
            then
                echo "Invalid argument!"
                exit 1
            fi
        
    esac
    shift
done

if test -z "$REPO"
then
    read -p "Type your Github repository name (owner/repo_name): " REPO
    URL=https://api.github.com/repos/$REPO/issues
fi

if test -z "$USERNAME"
then
    read -p "Type your Github username: " USERNAME
fi

if test -z "$PASSWORD"
then
    read -p "Type your Github password (won't be shown): " -s PASSWORD
fi

if test -z "$TITLE"
then
    read -p "Type the base title of issue: " TITLE
fi

if test -z "$LABELS"
then
    read -p "Type Issue labels (comma separated list): " LABELS
fi

if test "$MILESTONE" -eq 0
then
    read -p "Type Milestone ID: " MILESTONE
fi

if test "$QUANT" -eq 0
then
    read -p "Type quant of issues to create: " QUANT
fi

if test "$STEP_BEGIN" -eq 0
then
    read -p "Type initial step of issues to create: " QUANT
fi

for step in $(seq "$QUANT")
do
    # Increment initial step
    new_step=$(($step+$STEP_BEGIN))

    # Build the POST command
    command="{\"title\": \"$TITLE $new_step\", \"assignees\": [\"$USERNAME\"], \"milestone\": $MILESTONE, \"labels\": [\"$LABELS\"]}"

    # POST command
    response=$(curl -u "$USERNAME:$PASSWORD" -i "$URL" -X POST -d "$command")

    if test response == *"errors"
    then
        >&2 echo "Erro on create issue. Post response: $response"
    fi
done
