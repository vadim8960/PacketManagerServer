-- create database pmd;
begin;

drop table if exists _table;

create table _table(id int,
                    name text);

insert into _table values (0, 'hello');
insert into _table values (1, 'vadim');

select * from _table;

end;