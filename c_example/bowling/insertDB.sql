

use bowling_db;
create database if not EXISTS user_monthly_stats (
    ID integer primary key,
    username varchar(40) not null,
    year integer not null,
    month integer not null,   
    play_count  integer not null DEFAULT 0,
    UNIQUE KEY unique_user_month (username, year, month)
);
INSERT INTO score_records (username, play_date, score)
VALUES

use bowling_db;
select * from Book;

