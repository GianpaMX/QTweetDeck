CREATE TABLE "image" (
    "url" TEXT NOT NULL,
    "data" BLOB
);
CREATE TABLE user (
    "id" INTEGER NOT NULL,
    "name" TEXT,
    "screen_name" TEXT NOT NULL
, "profile_image_url" TEXT);
CREATE TABLE status (
    "id" INTEGER NOT NULL,
    "create_at" TEXT,
    "text" TEXT,
    "source" TEXT,
    "in_reply_to_status_id" INTEGER,
    "in_reply_to_user_id" INTEGER,
    "in_reply_to_screen_name" TEXT
);
