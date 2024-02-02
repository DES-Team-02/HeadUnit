import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_head_unit/provider/theme_provider.dart';
import 'package:provider/provider.dart';

class About extends StatelessWidget {
  About({super.key});

  final List<Map<String, dynamic>> developers = [
    {"name": "Jinhong Lee", "github": "Lagavulin9"},
    {"name": "Kian Warias", "github": "Kianwasabi"},
    {"name": "Seungwoo Lee", "github": "SeungWoo-L"},
  ];

  @override
  Widget build(BuildContext context) {
    return Consumer<ThemeModel>(
      builder: (context, theme, child) {
        final textColor = theme.textColor;
        return Expanded(
          child: ListView(
            children: [
              CupertinoListSection.insetGrouped(
                header: Text("Software", style: TextStyle(color: textColor)),
                children: [
                  CupertinoListTile.notched(
                    title: Text("Version", style: TextStyle(color: textColor)),
                    trailing: const Text("1.0"),
                  ),
                ],
              ),
              ...generateDevelopersList(developers, textColor),
              Container(
                  height: 100,
                  color: theme.mode == ThemeMode.light
                      ? CupertinoColors.systemGroupedBackground
                      : CupertinoColors.black),
            ],
          ),
        );
      },
    );
  }
}

List<Widget> generateDevelopersList(
    List<Map<String, dynamic>> developers, Color textColor) {
  return List.generate(developers.length, (index) {
    var developer = developers[index];
    return CupertinoListSection.insetGrouped(
      header: index == 0
          ? Text("Developers", style: TextStyle(color: textColor))
          : null,
      children: [
        CupertinoListTile.notched(
          title: Text("Name", style: TextStyle(color: textColor)),
          trailing: Text(developer["name"]),
        ),
        CupertinoListTile.notched(
          title: Text("Github ID", style: TextStyle(color: textColor)),
          trailing: Text(developer["github"]),
        ),
      ],
    );
  });
}