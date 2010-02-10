CREATE TABLE user (
    "id" INTEGER NOT NULL,
    "screen_name" TEXT NOT NULL,
    "name" TEXT
);
CREATE TABLE "status" (
    "id" INTEGER PRIMARY KEY NOT NULL,
    "text" TEXT,
    "created_at" TEXT,
    "source" TEXT,
    "in_reply_to_status_id" INTEGER,
    "in_reply_to_user_id" INTEGER,
    "in_reply_to_screen_name" TEXT
);
CREATE TABLE "image" (
    "url" TEXT NOT NULL,
    "data" BLOB
);
CREATE TABLE "user_image" (
    "id" INTEGER,
    "url" TEXT
);
