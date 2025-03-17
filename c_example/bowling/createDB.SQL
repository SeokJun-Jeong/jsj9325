create database if not EXISTS bowling_db;
grant all privileges on bowling_db.* to 'myuser'@'%';
use bowling_db;
create table bowling(
    ID integer primary key,
    username varchar(40) not null,
    play_date varchar(40) not null,
    score integer not null
);

