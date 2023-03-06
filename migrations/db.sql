begin;

drop table if exists _packets;

create table _packets
(
    id   serial not null primary key,
    path text
);

insert into _packets (path)
values ('/home/vadim/programs/cpp/PacketManagerServer/data/lib.txt'),
       ('/home/vadim/programs/cpp/PacketManagerServer/data/lib1.txt'),
       ('/home/vadim/programs/cpp/PacketManagerServer/data/lib2.txt');

end;