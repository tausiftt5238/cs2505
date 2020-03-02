#!/bin/bash 
# This script makes a backup of my ~/2505 directory. 
# Change the variables to make the script work for you:
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

# Copy the file to another host. 

scp $TARFILE $REMOTEID@$SERVER:$REMOTEDIR
# Create a timestamp in the logfile to record the backup operation. 
date >> $LOGFILE 
echo backup succeeded >> $LOGFILE

exit 0                           # return 0 on success
