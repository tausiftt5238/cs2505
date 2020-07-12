#!/bin/bash 
# This script makes a backup of a diectory to another server.
# Invocation: ./backup_2.sh DIRNAME 

if [[ $# -ne 1 ]]; then 
    echo "Invocation: ./backup_2.sh DIRNAME"
    exit 1
fi 

if [[ ! -d $1 ]]; then  # We saw that -d FILE is true IFF the directory exists, so ! before it means it doesn't exist
    echo "$1 is not a directory"
    exit 2
fi 

BACKUPDIR=$1 

BACKUPDIR=$HOME/cs2505/           # directory to be backed up 
TARFILE=$HOME/tmp/backup.tar      # tar file created during backup 
SERVER=rlogin.cs.vt.edu           # server to copy backup to 
REMOTEID=tausiftt52 # your ID on that server 
REMOTEDIR=/home/grads/tausiftt52 # dir to hold  backup on server 
LOGFILE=~/logs/2505_backup.log # local log file recording backups

# Move into the directory to be backed up 

cd $BACKUPDIR

# Run tar to create the archive. 

tar cf $TARFILE *

if [[ $? -ne 0 ]]; then  # #? return the exit code of last run command
    echo "Aborting: tar returned error code $?"
    exit 3
fi 

# Copy the file to another host. 

scp $TARFILE $REMOTEID@$SERVER:$REMOTEDIR

if [[ $? -ne 0 ]]; then  # same as previous block
    echo "Error: scp returned error code $?"
    exit 4 
fi 

# Create a timestamp in the logfile to record the backup operation. 
date >> $LOGFILE 
echo backup succeeded >> $LOGFILE

exit 0                           # return 0 on success
