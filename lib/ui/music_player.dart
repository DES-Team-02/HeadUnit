import 'dart:io';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:audio_video_progress_bar/audio_video_progress_bar.dart';
import 'package:flutter_head_unit/provider/theme_provider.dart';
import 'package:media_kit/media_kit.dart';
import 'package:metadata_god/metadata_god.dart';
import 'package:provider/provider.dart';
import 'package:rxdart/rxdart.dart';

class MetadataWidget extends StatelessWidget {
  MetadataWidget({super.key, required this.player});

  final Player player;
  final Widget default_image = DecoratedBox(
    decoration: BoxDecoration(boxShadow: const [
      BoxShadow(color: Colors.black12, offset: Offset(2, 4), blurRadius: 4)
    ], borderRadius: BorderRadius.circular(10)),
    child: ClipRRect(
      borderRadius: BorderRadius.circular(10),
      child: Image(
        image: FileImage(File('assets/unknown-album.png')),
        width: 200,
        height: 200,
      ),
    ),
  );

  @override
  Widget build(BuildContext context) {
    return StreamBuilder(
        stream: player.stream.playlist,
        builder: (context, snapshot) {
          if (snapshot.data == null) {
            return Column(
              children: [
                default_image,
                const SizedBox(height: 15),
                const Text(
                  "Not Playing",
                  style: TextStyle(fontSize: 25),
                ),
                const SizedBox(height: 40)
              ],
            );
          }
          final List<Media> _playlists = snapshot.data!.medias;
          final int _current_index = snapshot.data!.index;
          final String _selected_file = _playlists[_current_index].uri;
          return FutureBuilder(
              future: MetadataGod.readMetadata(file: _selected_file),
              builder: (context, snapshot) {
                final metadata = snapshot.data;
                final Widget AlbumCover = metadata?.picture == null
                    ? default_image
                    : DecoratedBox(
                        decoration: BoxDecoration(boxShadow: const [
                          BoxShadow(
                              color: Colors.black12,
                              offset: Offset(2, 4),
                              blurRadius: 4)
                        ], borderRadius: BorderRadius.circular(10)),
                        child: ClipRRect(
                          borderRadius: BorderRadius.circular(10),
                          child: Image(
                            image: MemoryImage(metadata!.picture!.data),
                            width: 200,
                            height: 200,
                          ),
                        ),
                      );
                return Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    AlbumCover,
                    const SizedBox(height: 15),
                    Text(
                      "${metadata?.title ?? 'Unknown Title'}",
                      style: const TextStyle(
                          fontSize: 25, fontWeight: FontWeight.bold),
                      overflow: TextOverflow.ellipsis,
                    ),
                    Text(
                      "${metadata?.artist ?? 'Unknown Artist'}",
                      style: const TextStyle(fontSize: 20),
                      overflow: TextOverflow.ellipsis,
                    ),
                    const SizedBox(height: 20)
                  ],
                );
              });
        });
  }
}

class PositionData {
  const PositionData(this.position, this.bufferedPosition, this.duration);

  final Duration position;
  final Duration bufferedPosition;
  final Duration duration;
}

class StreamProgressBar extends StatelessWidget {
  const StreamProgressBar({super.key, required this.player});

  final Player player;

  Stream<PositionData> get _positionDataStream =>
      Rx.combineLatest3<Duration, Duration, Duration?, PositionData>(
          player.stream.position,
          player.stream.buffer,
          player.stream.duration,
          (position, bufferedPosition, duration) => PositionData(
              position, bufferedPosition, duration ?? Duration.zero));

  @override
  Widget build(BuildContext context) {
    return StreamBuilder<PositionData>(
        stream: _positionDataStream,
        builder: (context, snapshot) {
          final positionData = snapshot.data;
          return ProgressBar(
            barHeight: 10,
            baseBarColor: Colors.grey[200],
            progressBarColor: Colors.grey[400],
            thumbColor: Colors.grey,
            progress: positionData?.position ?? Duration.zero,
            total: positionData?.duration ?? Duration.zero,
            onSeek: player.seek,
          );
        });
  }
}

class Controls extends StatelessWidget {
  const Controls({super.key, required this.player});

  final Player player;

  @override
  Widget build(BuildContext context) {
    final themeModel = Provider.of<ThemeModel>(context);
    return StreamBuilder(
        stream: player.stream.playing,
        builder: (context, snapshot) {
          final playing = snapshot.data;
          if (!(playing ?? false)) {
            return CupertinoButton(
              onPressed: player.play,
              child: Icon(CupertinoIcons.play_arrow_solid,
                  size: 50, color: themeModel.iconColor),
            );
          } else {
            return CupertinoButton(
              onPressed: player.pause,
              child: Icon(CupertinoIcons.pause_fill,
                  size: 50, color: themeModel.iconColor),
            );
          }
        });
  }
}

class AudioPlayerScreen extends StatelessWidget {
  const AudioPlayerScreen({super.key, required this.player});

  final Player player;

  @override
  Widget build(BuildContext context) {
    final themeModel = Provider.of<ThemeModel>(context);
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          MetadataWidget(player: player),
          SizedBox(
            width: 450,
            height: 50,
            child: StreamProgressBar(player: player),
          ),
          SizedBox(
            width: 600,
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                CupertinoButton(
                  onPressed: player.previous,
                  child: Icon(CupertinoIcons.backward_fill,
                      size: 40, color: themeModel.iconColor),
                ),
                Controls(player: player),
                CupertinoButton(
                  onPressed: player.next,
                  child: Icon(CupertinoIcons.forward_fill,
                      size: 40, color: themeModel.iconColor),
                ),
              ],
            ),
          ),
          const SizedBox(height: 10),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const Icon(CupertinoIcons.volume_mute),
              SizedBox(
                width: 410,
                child: StreamBuilder(
                    stream: player.stream.volume,
                    builder: (context, snapshot) {
                      final volume = snapshot.data ?? 50;
                      return CupertinoSlider(
                          min: 0,
                          max: 100,
                          value: volume,
                          onChanged: (volume) {
                            player.setVolume(volume);
                          },
                          activeColor: themeModel.sliderColor);
                    }),
              ),
              const Icon(CupertinoIcons.volume_up)
            ],
          )
        ],
      ),
    );
  }
}