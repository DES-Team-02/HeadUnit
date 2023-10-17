import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_head_unit/ui/app_drawer.dart';
import 'package:flutter_head_unit/ui/clock.dart';
import 'package:flutter_head_unit/ui/gear_selection.dart';
import 'package:window_manager/window_manager.dart';

const double displayWidth = 1024;
const double displayHeight = 600;
void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  // Must add this line.
  await windowManager.ensureInitialized();

  WindowOptions windowOptions = const WindowOptions(
    size: Size(displayWidth, displayHeight),
    skipTaskbar: false,
    titleBarStyle: TitleBarStyle.hidden,
  );
  windowManager.waitUntilReadyToShow(windowOptions, () async {
    await windowManager.show();
    await windowManager.focus();
  });
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Head Unit',
      theme: ThemeData(
        fontFamily: 'Kanit',
        colorScheme: ColorScheme.fromSeed(
            seedColor: const Color.fromRGBO(0xe1, 0xe1, 0xe1, 1)),
        useMaterial3: true,
      ),
      home: const MyHomePage(title: 'Head Unit'),
      debugShowCheckedModeBanner: false,
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  final GlobalKey<ScaffoldState> _scaffoldKey = GlobalKey<ScaffoldState>();

  int _selectedIndex = 0;

  void onTap(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      key: _scaffoldKey,
      floatingActionButton: CupertinoButton(
        child: const Icon(
          Icons.dashboard,
          size: 60,
        ),
        onPressed: () {
          debugPrint("button");
          _scaffoldKey.currentState!.openEndDrawer();
        },
      ),
      endDrawer: const AppDrawer(),
      body: Row(children: [
        const GearSelection(),
        Expanded(
            child: Stack(
          children: [
            Center(child: Text("$_selectedIndex")),
            const Positioned(top: 15, right: 20, child: Clock(size: 20))
          ],
        ))
      ]),
    );
  }
}