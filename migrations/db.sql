begin;

drop table if exists _packets;

create table _packets
(
    id   serial not null primary key,
    name text,
    path text
);

insert into _packets (name, path)
values
    ('importantlib.1.0', '/home/vadim/programs/cpp/PacketManagerServer/data/importantlib/1.0.tar.xz'),
    ('testlib.1.0', '/home/vadim/programs/cpp/PacketManagerServer/data/testlib/1.0.tar.xz');

end;