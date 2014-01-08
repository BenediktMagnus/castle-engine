//
//  ViewController.m
//  CastleEngineTest
//
//  Created by Jan Adamec on 18.11.13.
//  Copyright (c) 2013 Jan Adamec. All rights reserved.
//

#import "ViewController.h"
#import "OpenGLController.h"

@interface ViewController ()
{
    __weak IBOutlet UITableView *m_tableScenes;
    
    NSString *m_sSelectedFile;
    NSMutableArray *m_arrayFiles;
}
@end

//-----------------------------------------------------------------
//-----------------------------------------------------------------
@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    m_arrayFiles = [[NSMutableArray alloc] init];
    
    // documnets folder
    NSFileManager *fm = [NSFileManager defaultManager];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *sFolder = [paths objectAtIndex:0];
    NSArray *dirContents = [fm contentsOfDirectoryAtPath:sFolder error:nil];
    for (NSString *item in dirContents)
    {
        NSString *sFileExt = item.pathExtension;
        if ([sFileExt isEqualToString:@"wrl"]
            || [sFileExt isEqualToString:@"x3dv"]
            || [sFileExt isEqualToString:@"x3d"])
            [m_arrayFiles addObject:[sFolder stringByAppendingPathComponent:item]];
    }
    
    // sampledata folder
    NSString *sBundlePath = [[NSBundle mainBundle] bundlePath];
    sFolder = [sBundlePath stringByAppendingPathComponent:@"sampledata"];
    dirContents = [fm contentsOfDirectoryAtPath:sFolder error:nil];
    for (NSString *item in dirContents)
    {
        NSString *sFileExt = item.pathExtension;
        if ([sFileExt isEqualToString:@"wrl"]
            || [sFileExt isEqualToString:@"x3dv"]
            || [sFileExt isEqualToString:@"x3d"])
            [m_arrayFiles addObject:[sFolder stringByAppendingPathComponent:item]];
    }
}

//-----------------------------------------------------------------
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//-----------------------------------------------------------------
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

//-----------------------------------------------------------------
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return m_arrayFiles.count;
}

//-----------------------------------------------------------------
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [m_tableScenes dequeueReusableCellWithIdentifier:@"SceneFileCell"];
    cell.textLabel.text = [[m_arrayFiles objectAtIndex:indexPath.row] lastPathComponent];
    return cell;
}

//-----------------------------------------------------------------
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    m_sSelectedFile = [m_arrayFiles objectAtIndex:indexPath.row];
    [m_tableScenes deselectRowAtIndexPath:indexPath animated:NO];
    [self performSegueWithIdentifier:@"SegueOpen3D" sender:self];   // open 3D view
}

//-----------------------------------------------------------------
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"SegueOpen3D"])
    {
        OpenGLController *ctl = segue.destinationViewController;
        ctl.fileToOpen = m_sSelectedFile;
    }
}

@end